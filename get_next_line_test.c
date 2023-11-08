/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 12:51:37 by rjw           #+#    #+#                 */
/*   Updated: 2023/11/08 15:10:43 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int	new_line_found;
	// char	*cache;
	int		read_bytes;
// buffer[BUFFER_SIZE] = '\0';
	// ft_memset(buffer, 0, BUFFER_SIZE);
// int i = 0;
// int j = 0;
int k = 0;
	new_line_found = 0;
	read_bytes = 1;
// printf("%s\n", stash);
// stash = ft_strchr(stash, '\n', 0);
	while (read_bytes != 0 && new_line_found == 0)
	{
		// printf("i = %d\n", i);
		// printf("\n%d\n", new_line_found);
		// ft_writing("123\n");
		// stash = ft_strchr(stash, '\n', 0);
		// printf("%d\n", (stash == NULL));
		// printf("%s\n", stash);
		// ft_writing(stash);
		// ft_writing(buffer);
		ft_memset(buffer, 0, BUFFER_SIZE);
		// ft_writing(buffer);
		// printf("before read: %s\n", buffer);
		// printf("\n%d\n", new_line_found);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			printf("check it here\n");
			if (k > 0)
				free(stash);
			return (NULL);
		}
		if (read_bytes == 0 && k == 0)
		{
			// printf("read_bytes & k: \n");
			// printf("stash: %s\n", stash);
			// printf("read_bytes: %d\n", k);
			// printf("int k: %d\n", k);
			// printf("buffer: %s\n", buffer);
			
			// return (NULL);
			return (stash);
		}
		if (read_bytes == 0)
		{
			// printf("read_bytes: \n");
			// printf("stash: %s\n", stash);
			// printf("read_bytes: %d\n", k);
			// printf("int k: %d\n", k);
			return (stash);
		}
		// if (read_bytes == -1 || (read_bytes == 0 && k == 0))
		// {
		// 	printf("stash: %s\n", stash);
		// 	printf("read_bytes: %d\n", k);
		// 	printf("int k: %d\n", k);
		// 	// printf("%d\n", k);
		// 	if (read_bytes == 0 && k == 0)
		// 		return (NULL);
		// 	if (read_bytes == 0)
		// 	{
		// 		printf("0 it was:  %s\n", stash);
		// 		return (stash);
		// 	}
		// 	if (k > 0)
		// 	{
		// 		printf("check it here\n");
		// 		free(stash);
		// 	}
		// }
		// ft_writing(buffer);
		// if (read_bytes == 0 && k == 0)
		// 	return (NULL);
		// if (read_bytes == 0)
		// {
		// 	// printf("0 it was:  %s\n", stash);
		// 	return (stash);
		// 	// return (ft_memset(stash, 0 , BUFFER_SIZE));
		// }
		k++;
		stash = ft_strjoin(stash, buffer, &new_line_found);
		// ft_writing(stash);
		// ft_writing(&stash[4]);
		// ft_writing(buffer);
		// while (j < BUFFER_SIZE)
		// 	buffer[j++] = '\0';
		// j = 0;

		// ft_memset(buffer, 0, BUFFER_SIZE);
		// ft_writing(cache);
		// printf("read_bytes: %d\n", read_bytes);
		// printf("new_line: %d\n", new_line_found);
		// i++;

	}
// ft_writing("here");
	return (stash);
}

char	*get_next_line(int fd)
{
	// char static	*stored_line = "12345";
	// char static	*stored_line = "123\n45";
	char static	*stored_line;
	char		*line;
	char		*new_line;
// printf("%s\n", stored_line);
// ft_writing(stored_line);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_buffer(fd, stored_line);
	if (line == NULL)
		return (NULL);
	// ft_writing("line: ");
	// ft_writing(line);
	stored_line = (ft_strchr(line, '\n', 1));
	// ft_writing("stored line:");
	// ft_writing(stored_line);
	new_line = (ft_strchr(line, '\n', 2));
	if (new_line == NULL)
	{
		printf("here also\n");
		free(line);
		return (NULL);
	}
	// ft_writing("new_line:");
	// ft_writing(new_line);
	if (stored_line == new_line)
	{
		// ft_writing("Should be here");
		stored_line = NULL;
		// free(new_line);
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


