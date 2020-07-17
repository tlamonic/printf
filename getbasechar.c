#include "libftprintf.h"

char	getbasechar(int c)
{
	if (c % 16 == 10)
		return ('a');
	else if (c % 16 == 11)
		return ('b');
	else if (c % 16 == 12)
		return ('c');
	else if (c % 16 == 13)
		return ('d');
	else if (c % 16 == 14)
		return ('e');
	else if (c % 16 == 15)
		return ('f');
	else
		return (c + 48);
}
