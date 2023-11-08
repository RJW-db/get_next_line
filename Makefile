NAME=get_next_line.a

CFLAGS=-Wall -Werror -Wextra

RM=rm -f

SRC =	get_next_line_tests.c \
		get_next_line_utils.c

OBJ=$(SRC: .c = .o)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c <$ -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:
	flcean all

x:
	all clean

.Phony: all, clean, fclean, re, x