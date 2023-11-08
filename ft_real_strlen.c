/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_real_strlen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 23:35:58 by rjw           #+#    #+#                 */
/*   Updated: 2023/11/02 01:36:58 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	ft_real_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] == '\0')
	{
		if (str[i] == '\0' && str[i + 1] == '\0')
			break ;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char *str1 = "here\0";

// 	printf("%d", ft_real_strlen(str1));
// }

// int	ft_real_strlen(const char *str1, const char *str2)
// {
// 	return ((int)(str2 - str1) - 1);
// }

// int	main(void)
// {
// 	char *str1 = "\0\0\0";
// 	char *str2 = "end";

// 	printf("%d", ft_real_strlen(str1, str2));
// }

// int main(void)
// {
// 	char *str1 = "\0\0\0";
// 	char *str2 = "end";

// 	printf("str1: %p\n", (void *)str1);
// 	printf("str2: %p\n", (void *)str2);
// 	int length = (int)(str2 - str1) - 1;

// 	printf("Length of str1: %d\n", length);

// 	return (0);
// }

// int	ft_real_strlen(const char *str, const char *end)
// {
// 	int	i;
// 	int	j;
// 	int	flag;
//
// 	i = 0;
// 	flag = 0;
// 	while (str[i] || str[i] == '\0')
// 	{
// 		j = 0;
// 		while (str[i] == end[j] && j < (int)strlen(end))
// 		{
// 			flag = 1;
// 			i++;
// 			j++;
// 		}
// 		if (flag == 1)
// 			break ;
// 		i++;
// 		if (i == 500)
// 			return (0);
// 	}
// 	return (i - j - 1);
// }

// int	main(void)
// {
// 	char *string = "\0\0\0\0";
// 	// char string[] = "1234\0abc\0";
// 	char *ending = "XYZ3!3ZYX";
// 	printf("%p\n", string);
// 	// printf("%lu", sizeof(string));
// 	printf("%d\n", ft_real_strlen(string, ending));
// 	return (0);
// }
