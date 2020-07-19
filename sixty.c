#include "libftprintf.h"
#include <stdio.h>
char	*sixty(unsigned long long dig)
{
	char				*str;
	size_t				size;
	size_t				tmp;

	tmp = 0;
	size = sizeof(long long) * 8 + 1;
	str = (char*)malloc(sizeof(char) * (size));
	if (!str)
		return (0);
	while (tmp < size)
		str[tmp++] = '\0';
	tmp = 0;
	while (dig >= 16)
	{
		str[tmp++] = getbasechar(dig % 16);
		dig /= 16;
	}
	str[tmp] = getbasechar(dig);
	reversstr(str, ft_strlen(str));
	return (str);
}
