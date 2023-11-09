/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 12:51:37 by rjw           #+#    #+#                 */
/*   Updated: 2023/11/09 12:00:58 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		new_line_found;
	int		read_bytes;
	int		k;

	new_line_found = 0;
	read_bytes = 1;
	k = 0;

	while (read_bytes != 0 && new_line_found == 0)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		// printf("the buffer: %s\n", buffer);
		if (read_bytes == -1)
		{
			if (k > 0)
				free(stash);
			return (NULL);
		}
		if (read_bytes == 0)
			return (stash);
		k++;
		stash = ft_strjoin(stash, buffer, &new_line_found);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char static	*stored_line;
	char		*line;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_buffer(fd, stored_line);
	if (line == NULL)
		return (NULL);
	stored_line = (ft_strchr(line, '\n', 1));
	new_line = (ft_strchr(line, '\n', 2));
	if (new_line == NULL)
	{
		free(line);
		return (NULL);
	}
	if (stored_line == new_line)
	{
		stored_line = NULL;
		return (new_line);
	}
	return (new_line);
}

int	main(void)
{
	write(1, "\n\n\n\n\n\n", 6);
	char*	fileName = "info.txt";
	int fd = open(fileName, O_RDWR);
	if(fd == -1)
	{
		printf("\nError Opening File!!\n");
		exit(1);
	}
	else
		printf("\nFile \"%s\" opened sucessfully!\n", fileName);
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	size_t	i = 0;
	size_t	limit = 9;
	char *retrieved_str;
	while (i < limit)
	{
		retrieved_str = get_next_line(fd);
		// ft_writing("int main: ");
		// ft_writing(retrieved_str);
		// printf("\n");
		printf("int main, index %zu: %s\n\n\n", i + 1, retrieved_str);
		// if (i <= limit - 1)
		// 	free(retrieved_str);
		// get_next_line(fd);
		// get_next_line(fd);
		// ft_writing(get_next_line(fd));
		// ft_writing(get_next_line(fd));
		i++;
	}
	return (0);
}


