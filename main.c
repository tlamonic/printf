#include "libftprintf.h"
#include <stdio.h>
int main()
{
	char *s = "Hello World!";
	ft_printf("%#5s", s);
	return 0;
}
