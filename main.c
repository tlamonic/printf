#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	print(char *str, ...)
{
	va_list vlist;
	unsigned int str1;
	va_start(vlist, str);
	str1 = va_arg(vlist, unsigned int);
	printf("%u\n", str1);
	va_end(vlist);
}

int main()
{
//	char *ptr = &c;
	ft_printf("%-10.5d%%\n", 123);
	printf("%-10.5d", 123);
}
