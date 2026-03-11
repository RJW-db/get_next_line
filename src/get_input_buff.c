/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input_buff.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/23 14:49:53 by rjw           #+#    #+#                 */
/*   Updated: 2025/05/09 15:23:25 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#define MOVE_CURSOR_UP "\033[F"
#define CLEAR_LINE "\033[2K"

static ssize_t	process_input(char *buff, ssize_t rd, ssize_t buff_size);
static ssize_t	empty_filedescriptor(char *buff, ssize_t buff_size, bool mute);
static void		print_str_fd(const char *s, int fd);

ssize_t	get_user_input(char *buff, ssize_t buff_size, char *msg, bool mute)
{
	ssize_t	rd;

	if (buff == NULL || buff_size <= 0)
		return (-1);
	if (msg != NULL)
		print_str_fd(msg, STDOUT_FILENO);
	rd = read(STDIN_FILENO, buff, (size_t)buff_size);
	if (rd > 0 && rd <= buff_size)
	{
		rd = process_input(buff, rd, buff_size);
		if (rd > 0)
			return (rd);
		if (rd == -1)
			rd = empty_filedescriptor(buff, buff_size, mute);
		if (rd != -1)
			return (print_str_fd(MOVE_CURSOR_UP CLEAR_LINE, STDOUT_FILENO), \
			get_user_input(buff, buff_size, msg, mute));
	}
	buff[0] = '\0';
	if (rd == -1)
		return (-1);
	if (msg != NULL)
		print_str_fd("\n", STDOUT_FILENO);
	return (0);
}

static ssize_t	process_input(char *buff, ssize_t rd, ssize_t buff_size)
{
	ssize_t	index;

	if (buff[0] == '\n')
		return (0);
	index = 0;
	while (index < rd && buff[index] != '\n')
		++index;
	if (index == rd)
		return (-1);
	if (buff[index] == '\n')
	{
		buff[index] = '\0';
		return (index);
	}
	if (rd < buff_size)
		buff[rd++] = '\0';
	if (buff[rd - 1] == '\0')
		return (rd);
	return (-1);
}

static ssize_t	empty_filedescriptor(char *buff, ssize_t buff_size, bool mute)
{
	ssize_t	rd;

	rd = buff_size;
	while (rd == buff_size)
	{
		rd = read(STDIN_FILENO, buff, (size_t)buff_size);
		if (rd < buff_size || buff[rd - 1] == '\n')
		{
			break ;
		}
	}
	buff[0] = '\0';
	if (!mute) {
		print_str_fd(MOVE_CURSOR_UP CLEAR_LINE, STDOUT_FILENO);
		printf("You're only allowed up to %ld characters\n\n", buff_size - 1);
	}
	return (rd);
}

static void	print_str_fd(const char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	if (write(fd, s, len) == -1)
		perror("print_str_fd: write");
}
