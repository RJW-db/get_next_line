/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 11:35:24 by rjw           #+#    #+#                 */
/*   Updated: 2023/11/08 16:19:10 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c, int skip_n);
char			*new_line(char *s, int i);
char			*ft_strjoin(const char *s1, const char *s2, int *n_line);
void			*ft_memset(void *b, int c, size_t len);

void	ft_writing(char *str);

// # endif
#endif