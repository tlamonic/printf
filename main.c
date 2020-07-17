#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	print(unsigned long long a)
{
	int i=0;
	unsigned long long tmp = a;
	while(a)
	{
		i++;
		a/=16;
	}
	char *str = malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	while (tmp)
	{
		str[i--] = getbasechar(tmp);
		tmp/=16;
	}
	i++;
	while (str[i])
		printf("%c", str[i++]);
}
int main()
{
	int a = 21;
	int *b = &a;
	printf("%p\n0x", b);
	print((unsigned long long)b);
}
