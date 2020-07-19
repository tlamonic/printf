#include "libftprintf.h"

char	getbasechar(int c)
{
	if (c > 9 && c < 16)
		return (c + 87);
	else if (c >= 0 && c < 10)
		return (c + '0');
	else
		return ('~');
}
