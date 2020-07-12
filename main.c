#include "libftprintf.h"
#include <stdio.h>
int main()
{
	char c = 'a';
	long long i = 111111111111111111111111111111111111111111111111111111111;
	char *str = "Hello1234567890||||||";
	//printf("%.*s%nA\n", 255, "HelloThere", &i);
	printf("%e\n", i);
	//ft_printf("%f\n", i);
	return 0;
}
