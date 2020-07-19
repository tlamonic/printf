#include "libftprintf.h"

void	reversstr(char *str, size_t size)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < size - 1)
	{
		tmp = str[i];
		str[i] = str[size - 1];
		str[size - 1] = tmp;
		size--;
		i++;
	}
}
