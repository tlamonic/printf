#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	printf("%-12.4d%%\n", -245);
	ft_printf("%-12.4d", -245);
	//ft_printf("%-15.12d", -2147483647);
}
