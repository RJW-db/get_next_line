// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   get_next_line.c                                    :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: rjw <rjw@student.codam.nl>                   +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2023/10/29 12:51:37 by rjw           #+#    #+#                 */
// /*   Updated: 2023/11/02 16:40:26 by rjw           ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// void	writing(char *str)
// {
// 	int	i;
// 	int	len;

// 	// len = ft_real_strlen(str);
// 	len = strlen(str);
// 	i = 0;
// 	while (len--)
// 	{
// 		if (str[i] == '\n')
// 			write(1, "\\n", 2);
// 		// else if (str[i] == '\0')
// 		// 	write(1, "\\0", 2);
// 		else
// 			write(1, &str[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }

// // void	writing(char *str)
// // {
// // 	// int i = 0;
// // 	// while (str[i])
// // 	// 	i++;
// // 	if (*str != '\0')
// // 		while (*str)
// // 		{
// // 			if (*str == '\n')
// // 				write(1, "\\n", 2);
// // 			else
// // 				write(1, str, 1);
// // 			str++;
// // 		}
// // 	else
// // 		write(1, "\\0", 2);
// // 	write(1, "\n", 1);
// // }

// char	*get_next_line(int fd)
// {
// 	char		buffer[BUFFER_SIZE];
// 	char		*new_line;
// 	static char	remember[BUFFER_SIZE];
// 	int	i;
// 	int j;
// 	int k;
// 	if (read(fd, buffer, BUFFER_SIZE) == -1)
// 	{
// 		close(fd);
// 		return (NULL);
// 	}
// 	i = 0;
// 	if (buffer[0] == '\n')
// 	{
// 		write(1, "-----------: ", 13);
// 		// writing("-----------: ");
// 		writing(buffer);
// 	}
// 	else
// 	{
// 		write(1, "-----------: ", 13);
// 		writing(buffer);
// 	}
// 	while (buffer[i] && i < BUFFER_SIZE)
// 	{
// 		if (buffer[i] == '\n')
// 		{
// 			i++;
// 			break ;
// 		}
// 		i++;
// 	}
// 	k = 0;
// 	while (remember[k] != '\0')
// 		k++;	
// 	write(1, "1: ", 3);
// 	writing(remember);
// 	new_line = malloc((i + k + 1) * sizeof(char));
// 	if (!new_line)
// 		return (NULL);
// 	j = 0;
// 	while (remember[j] != '\0')
// 	{
// 		new_line[j] = remember[j];
// 		remember[j] = '\0';
// 		j++;
// 	}
// 	write(1, "========", 8);
// 	writing(remember);
// 	j = 0 + k;
// 	while (j < i)
// 	{
// 		new_line[j] = buffer[j - k];
// 		j++;
// 	}
// 	j = 0;
// 	while (i < BUFFER_SIZE)
// 	{
// 		remember[j] = buffer[i];
// 		write(1, "2: ", 3);
// 		writing(remember);

// 		j++;
// 		i++;
// 	}
// 	if (remember[0] == '\0')
// 	{
// 		write(1, "2: ", 3);
// 		writing("\0");
// 	}
// 	write(1, "new_line: " , 10);
// 	writing(new_line);

// 	return (new_line);
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
//         // printf("\nFile \"%s\" opened sucessfully!\n", fileName);
//     }
// 	// get_next_line(fd);

// 	size_t	i = 0;
// 	while (i++ < 3)
// 		get_next_line(fd);
// 		// printf("%s\n", get_next_line(fd));1

// 	printf("\n\n\n\n\n\n");
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
