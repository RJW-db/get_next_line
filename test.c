#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
// #define BUFFER_SIZE 5

// void	test(const char* str)
// {
	// t_list	*store;

	// store->cache = (void *)str;

	// printf("%s\n", (char *)store->cache);

	// store->cache = ((void *)"would something like this work");
	// printf("%s\n", (char *)store->cache);


	// static char	*stash;

	// stash = (char *)str;
	// printf("%s\n", stash);
	// stash = "creating a new string over here which is bigger than the first";
	// printf("%s\n", stash);



	
	// (void)str;

	// char		tmp[30] = "How are you today";
	// char	*line = tmp;
	// printf("%s\n", line);

	// char		ptr[12] = "what is here";
	// 	 line = ptr;

	// 	printf("%s\n", line);

// }

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

void	test(const char *str)
{
	static char	**line;
	char		word[5] = "World";

	line = (char **)malloc((2 + 1) * sizeof(char));

	line[0] = (char *)malloc((5 + 1) * sizeof(char));
	line[1] = (char *)malloc((5 + 1) * sizeof(char));

	ft_strlcpy(line[0], str, 6);
	ft_strlcpy(line[1], word, 6);

	printf("%s\n", line[0]);
	printf("%s\n", line[1]);
}

// int main(void) {
// 	char *str = "Hello";

// 	test(str);
// 	str = "Spoon";
// 	test(str);
// 	return 0;
// }
