/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 17:19:27 by rjw           #+#    #+#                 */
/*   Updated: 2023/11/08 14:57:47 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	((unsigned char *)b)[len] = (unsigned char)c;
	while (len-- != 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c, int skip_n)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		if ((char)c == '\0')
			return ((char *)&s[ft_strlen(s)]);
		while (s[i] != '\0')
		{
			// printf("%s - %c\n", (char *)s, s[i]);
			// ft_writing((char *)s);
			// ft_writing(" - ");
			// ft_writing((char *)&s[i]);
			if (s[i] == (char)c)
			{
				
				// ft_writing((char *)s);
				// ft_writing((char *)&s[i]);
				// printf("%s\n",(char *)&s[i]);
				if (skip_n == 1)
					return ((char *)&s[++i]);
				if (skip_n == 2)
					return (new_line((char *)s, ++i));
				return ((char *)&s[i]);
				// return (NULL);
			}
			i++;
		}
	}
	// printf("do we get here\n\n");
	// return (NULL);
	return ((char *)s);
}

char	*new_line(char *s, int i)
{
	char	*return_line;
// ft_writing(s);
// printf("%d\n",i);
	return_line = (char *)malloc((i + 1) * sizeof(char));
	if (return_line == NULL)
	{
		printf("here\n");
		return (NULL);
	}
	return_line[i--] = '\0';
	while (i >= 0)
	{
		return_line[i] = s[i];
		// ft_writing(&return_line[i]);
		// printf("%c\n", s[i]);
		i--;
	}
	// ft_writing(&return_line[2]);
	return (return_line);
}

char	*ft_strjoin(const char *s1, const char *s2, int *n_line)
{
	size_t	i;
	size_t	j;
	char	*s3;
	size_t	s1_check;
// ft_writing((char *)s1);

	s1_check = 0;
	if (s1 != NULL)
		s1_check = ft_strlen(s1);
	if (s2 == NULL)
		return (NULL);
	s3 = (char *)malloc((s1_check + ft_strlen(s2) + 1) * sizeof(char));
	if (s3 == NULL)
	{
		// ft_writing("check");
		return (NULL);
	}
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		if (s2[j] == '\n')
			*n_line = 1;
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	// ft_writing(s3);
	return (s3);
}
