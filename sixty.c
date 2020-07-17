#include "libftprintf.h"
#include <stdio.h>
char	*sixty(unsigned long long dig)
{
	unsigned long long	tmp;
	char				*str;
	int					size;

	tmp = dig;
	size = 0;
	while (tmp)
	{
		size++;
		tmp /= 16;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	size = 0;
	while (dig)
	{
		printf("%c", getbasechar(dig));
		//str[size++] = getbasechar(dig);
		dig /= 16;
	}
	str[size++] = '\0';
	return (str);
}
