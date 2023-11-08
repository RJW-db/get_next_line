/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 13:38:39 by rjw           #+#    #+#                 */
/*   Updated: 2023/11/08 13:31:28 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"
#include "../get_next_line.h"
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
// char	*ft_strchr(const char *s, int c);
char	*ft_strchr(const char *s, int c, int skip_n);
char	*ft_strchr2(const char *s, int c, int skip_n);
char	*ft_strchr3(const char *s, int c, int skip_n);
char	*new_line(char *s, int i);
char	*ft_strjoin(const char *s1, const char *s2, int *n_line);
void	*ft_memset(void *b, int c, size_t len);


int	main(void)
{
	char *tmp = "jejejeje";
	// test1();
	ft_strlen(tmp);
	return (0);
}
