/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 12:34:52 by rjw           #+#    #+#                 */
/*   Updated: 2023/11/08 13:25:33 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"
#include "../get_next_line.h"

void	test1(void)
{
	write(1, "\n\n\n\n\n\n", 6);
	char*	fileName = "test1.txt";
	int fd = open(fileName, O_RDWR);
	if(fd == -1)
	{
		printf("\nError Opening File!!\n");
		exit(1);
	}
	// else
	// 	printf("\nFile \"%s\" opened sucessfully!\n", fileName);
	size_t	i = 0;
	size_t	limit = 8;
	char *retrieved_str;
	while (i++ < limit)
	{
		retrieved_str = get_next_line(fd);
		// ft_writing("int main: ");
		// ft_writing(retrieved_str);
		// printf("\n");
		printf("int main: %s\n\n",retrieved_str);
		if (i <= limit - 1)
			free(retrieved_str);
		// get_next_line(fd);
		// get_next_line(fd);
		// ft_writing(get_next_line(fd));
		// ft_writing(get_next_line(fd));
		
	}
	close(fd);
	// return (0);
}
