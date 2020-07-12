#include "libftprintf.h"

/*
**This function return number with information about flags.
**
**Return value has info about flags in next order:
**___________
**|5|4|3|2|1|	<- bit
**|-|+| |#|0|	<-flag
**-----------
*/

static int	getflags(const char *p1, const char *p2)
{
	int			bits;

	bits = 0;
	while (++p1 < p2)
	{
		if (*p1 == '#')
			bits |= 2;
		else if (*p1 == '-')
		{
			bits |= 16;
			bits &= 30;
		}
		else if (*p1 == '0' && !(bits & 16) && !ft_isdigit(*(p1 - 1)) &&
				!(*(p1 - 1) == '.' && !ft_isdigit(*(p1 + 1))))
			bits |= 1;
		else if (*p1 == '+')
		{
			bits |= 8;
			bits &= 27;
		}
		else if (*p1 == ' ' && !(bits & 8))
			bits |= 4;
	}
	return (bits);
}

static int	getprecision(const char *p1, const char *p2, va_list *lst)
{
	int			prec;
	const char	*tmp;

	prec = -1;
	while (p2 > p1)
	{
		tmp = p2;
		while (ft_isdigit(*p2))
			p2--;
		if (*p2 == '.' && !ft_isdigit(*(p2 + 1)))
			return (0);
		if (*p2 == '.' && p2 != tmp)
		{
			prec = ft_str_to_nbr((char*)(p2 + 1), (char*)tmp, 1);
			break ;
		}
		else if (*p2 == '*' && *(p2 - 1) == '.')
		{
			prec = va_arg(*lst, int);
			break ;
		}
		p2--;
	}
	return (prec);
}

static int	getwidth(const char *p1, const char *p2, va_list *lst)
{
	int			width;
	const char	*tmp;

	width = 0;
	while (p2 > p1)
	{
		tmp = p2;
		while (ft_isdigit(*p2))
			p2--;
		if (*p2 == '*' && *(p2 - 1) != '.')
		{
			width = va_arg(*lst, int);
			break ;
		}
		else if (*p2 != '.' && p2 != tmp)
		{
			width = ft_str_to_nbr((char*)(p2 + 1), (char*)tmp, 1);
			break ;
		}
		p2--;
	}
	return (width);
}

/*
**This function return array with information about flags, width, precision,
**modifiers.
**
**First element of array contain info about flags.
**Second element of array contain width.
**Third element of array contain precision.
**Fourth element of array contain info about modifiers.
*/

int			*getformat(const char *p1, const char *p2, va_list *list)
{
	int			*res;

	if (!p1 && !p2)
		return (NULL);
	res = ft_calloc(3, sizeof(int));
	if (!res)
		return (NULL);
	res[0] = getflags(p1, p2);
	res[1] = getwidth(p1, p2, list);
	res[2] = getprecision(p1, p2, list);
	return (res);
}
