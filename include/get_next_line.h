/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/11 20:34:29 by rjw           #+#    #+#                 */
/*   Updated: 2025/05/09 15:24:41 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <unistd.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10240
# endif

# if defined(__APPLE__) || defined(__MACH__)
#  include <limits.h>
#  define MAX_FD OPEN_MAX
# elif defined(__linux__) || defined(__FreeBSD__)
#  define MAX_FD 1024
# elif defined(_WIN32)
#  define MAX_FD 512
# else
#  define MAX_FD 256
# endif

char	*get_next_line(int fd);
char	*get_next_line_fds(int fd);

/**
 * @brief Reads user input from standard input into a buffer, with optional
 * message display and muting.
 * @param buff The buffer to store the user input.
 * @param buff_size The size of the buffer.
 * @param msg An optional message to display before reading input. Can be NULL.
 * @param mute If true, suppress output when the input exceeds the buffer size.
 * @return The number of bytes read into the buffer, 0 on EOF, or -1 on error.
 */
ssize_t	get_user_input(char *buff, ssize_t buff_size, char *msg, bool mute);

#endif
