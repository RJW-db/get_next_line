/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 12:51:37 by rjw           #+#    #+#                 */
/*   Updated: 2023/10/31 12:03:08 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #define BUFFER_SIZE	

char	*get_next_line(int fd)
{
	char buffer[1024];
	int bytesRead = read(fd, buffer, sizeof(buffer));
	char *ptr = "here";

    printf("%d bytes read!\n", bytesRead);
    printf("File Contents: %s\n", buffer);
	return (ptr);
}

int	main(void)
{
	// char*	fileName = "info.txt";
	// int fd = open(fileName, O_RDWR);

	if (BUFFER_SIZE)
		printf("\n%d\n", BUFFER_SIZE + 5);
	else
	{
		printf("here");
	}
    
    // if(fd == -1){
    //     printf("\nError Opening File!!\n");
    //     exit(1);
    // }
    // else
	// {
    //     printf("\nFile \"%s\" opened sucessfully!\n", fileName);
    // }
	// get_next_line(fd);

	return (0);
}


// int	main(void)
// {
// 	char	*str = "File descriptor";
// 	int		fd = open("info.txt", O_CREAT | O_EXCL | O_WRONLY, 0644);
// read();
// 	while (*str)
// 		write(fd, str++, 1);
// 	return (0);
// }
