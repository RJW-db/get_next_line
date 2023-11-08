/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writing.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 13:35:46 by rjw           #+#    #+#                 */
/*   Updated: 2023/11/04 14:48:59 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_writing(char *str)
{
	int	i;
	int	len;

	if (str == NULL || str[0] == '\0')
	{
		write(1, "\\0\n", 3);
		return ;
	}
	len = ft_strlen(str);
	i = 0;
	while (len--)
	{
		if (str[i] == '\n')
			write(1, "\\n", 2);
		else if (str[i] == '\0')
			write(1, "\\0", 2);
		else
			write(1, &str[i], 1);
		i++;
	}
	// write(1, "\\0", 2);
	write(1, "\n", 1);
}
