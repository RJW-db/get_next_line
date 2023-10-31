// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   get_next_line_test.c                               :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: rjw <rjw@student.codam.nl>                   +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2023/10/29 12:51:37 by rjw           #+#    #+#                 */
// /*   Updated: 2023/10/31 21:14:42 by rde-brui      ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	char		buffer[BUFFER_SIZE];
// 	int			bytes_read;
// 	char		*return_line;
// 	static char	remember[BUFFER_SIZE];
// 	char		tmp[BUFFER_SIZE];
// 	int	i;
// 	int j;
// 	int k;
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);

// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n' && i < BUFFER_SIZE && i + k < BUFFER_SIZE)
// 		i++;
// 	if (buffer[i] == '\n' && i < BUFFER_SIZE)
// 		i++;
// 	if (buffer[i] == '\0')
// 		return (NULL);
// 	// printf("%d\n", i);
// 	// printf("   %s\n", buffer);
// 	return_line = malloc((i + k + 1) * sizeof(char));
// 	if (!return_line)
// 		return (NULL);
// 	// return_line[i--] = '\0';
// 	i--;
// 	i = i + k;
// 	while (i + k > 0)
// 	{
// 		if (k > 0)
// 		{
// 			k--;
// 			return_line[k] = tmp[k];
// 		}
// 		else
// 		{
// 			i--;
// 			return_line[i] = buffer[i];
// 		}
// 	}
// 	j = 0;
// 	while (i < BUFFER_SIZE)
// 	{
// 		remember[j++] = buffer[i++];
// 	}
// 	printf("%s\n", remember);
	
//     // printf("%d bytes read!\n", bytesRead);
// 	// printf("File Contents: %s\n", buffer);
// 	return (return_line);
// }

// int	main(void)
// {
// 	char*	fileName = "info.txt";
// 	int fd = open(fileName, O_RDWR);

//     if(fd == -1){
//         printf("\nError Opening File!!\n");
//         exit(1);
//     }
//     else
// 	{
//         printf("\nFile \"%s\" opened sucessfully!\n", fileName);
//     }
// 	// get_next_line(fd);

// 	size_t	i = 0;
// 	while (i++ < 10)
// 		printf("%s\n", get_next_line(fd));

// 	return (0);
// }

// // int	main(void)
// // {
// // 	char	*str = "File descriptor";
// // 	int		fd = open("info.txt", O_CREAT | O_EXCL | O_WRONLY, 0644);
// // read();
// // 	while (*str)
// // 		write(fd, str++, 1);
// // 	return (0);
// // }
