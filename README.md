# get_next_line
`get_next_line()` is a 42-style utility function that returns **one line per call** from a file descriptor, handling buffering internally.  
A “line” is returned including the terminating `\n`, except when EOF is reached and the file does not end with `\n`.

This project also includes an extra utility function I wrote: `get_user_input()`, a small helper to read user input from `stdin` into a fixed buffer (optionally printing a prompt message and optionally muting overflow output).

## Features
- Minimal reading: returns as soon as a newline is found (doesn’t read the entire file up front).
- Compile-time buffer size: works with and without `-D BUFFER_SIZE=n` (evaluators will change it).
- Bonus-ready behavior (if you did it): supports interleaved reads across multiple fds without mixing state.


## Table of Contents
- [Build](#build)
- [Compile & link](#compile--link)
- [Examples](#examples)
- [Project rules](#project-rules-42-subject)
- [Bonus](#bonus)
- [Extra function: get_user_input](#extra-function-get_user_input)
- [Testing checklist](#testing-checklist)


## Build

```sh
make          # build get_next_line.a
make clean    # remove build artifacts
make fclean   # clean + remove push_swap checker (and extern deps)
make re       # fclean + build
make valgrind # debug flags
make debug    # debug flags + sanitizers (per Makefile)
```

All targets and flags are defined in the [`Makefile`](Makefile).

## Compile & link

The project must compile with and without `-D BUFFER_SIZE=n`, and evaluators will change `BUFFER_SIZE` during testing.

```sh
cc -I include -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.a -o demo
```

## Examples

### Read a file line-by-line (`get_next_line`)
Use case: parse a text file one line at a time without manually managing buffering.

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        // line includes '\n' if it was present in the input
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Notes:
- The returned pointer is heap-allocated; you must free(line) after use.
- If the file does not end with \n, the last returned line won’t contain it.


Read from stdin interactively (get_next_line).
Use case: simple “read a line from terminal” loop using the same primitive.

```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char *line;

    while (1)
    {
        write(STDOUT_FILENO, "Give input: ", 12);
        // Prompt for input, then read a line; user can break with Ctrl+D (EOF)
        line = get_next_line(STDIN_FILENO);
        if (!line)
            break;

        printf("You typed: %s", line);
        free(line);
    }
    return (0);
}
```

Prompt + fixed-buffer input (get_user_input)

Use case: you want input without allocations, into a buffer you control (useful for menus / small commands).

```c
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char    buff[2];
    ssize_t n;

    n = get_user_input(buff, sizeof(buff), "Type your input: ", false);
    if (n < 0)
        return (1);

    if (n == 0)
    {
        printf("No input / EOF\n");
        return (0);
    }

    printf("You entered: %s\n", buff);
    return (0);
}
```

### Notes:
- get_user_input() writes into your buffer and ensures it’s NUL-terminated.
- If the user enters more than buff_size - 1 characters, the function drains remaining input.
- if `mute == true` it suppresses extra output (per your implementation).

## Project rules (42 Subject)

### Mandatory part
- Function name: `get_next_line`
- Prototype: `char *get_next_line(int fd);`
- Turn-in files (typical): `get_next_line.c`, `get_next_line.h`
- Return value:
  - The line read (including `\n` if present).
  - `NULL` if there is nothing left to read or an error occurs.

### Authorized external functions
- `read`, `malloc`, `free`

### Compilation requirement (BUFFER_SIZE)
- Must compile with and without `-D BUFFER_SIZE=n`, and evaluators will test multiple values.

### Bonus
Bonus requirements summary:
- Use only **one** static variable.
- Must handle multiple file descriptors at the same time (interleaving calls across fds must not lose state).

## Extra function: get_user_input
`get_user_input()` is an additional helper (not part of the 42 subject) that reads a single line from `STDIN_FILENO` into a caller-provided buffer.

- Optional `msg` prompt printed to stdout before reading.
- `buff_size` must be at least 2 (1 char + `\0` terminator).
- The stored string is always NUL-terminated, and the trailing `\n` is removed when present.

Return values:
- `> 0`: number of characters stored (excluding `\n`)
- `0`: EOF (e.g., user pressed Ctrl+D to signal EOF)
- `-1`: error (or invalid arguments)

Overflow behavior:
- If the user types more than `buff_size - 1` characters, the function drains the rest of the line from stdin and clears `buff`.
- If `mute == true`, overflow is handled silently (no warning message).
- If `mute == false`, it prints a warning and uses ANSI escape codes to adjust terminal output (cursor up + clear line).


## Testing checklist

- Test multiple BUFFER_SIZE values: 1, 42, 99999, very large values; verify no leaks/crashes and correct line splitting.
- Test files with: empty file; single line without \n; last line with \n; many short lines; very long line; alternating line lengths.
- Test standard input (stdin) and non-regular fds (pipes) if possible, since fds aren’t only regular files.
- (Bonus) Interleave reads across multiple fds: read fd3, fd4, fd3, fd5, etc., ensuring each fd continues correctly.
