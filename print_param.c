#include "libftprintf.h"

static int		getandprintparam(const char *p2, va_list *vars, int *format)
{
	int			errflag;

	errflag = 0;
	if (*p2 == 'c')
		errflag = printchar(va_arg(*vars, int), format);
	else if (*p2 == 's')
		errflag = prints(va_arg(*vars, int*), format);
	else if (*p2 == 'p')
		errflag = printp(va_arg(*vars, void*), format);
	else if (*p2 == '%')
		errflag = printpcnt(format);
	else if (*p2 == 'd' || *p2 == 'i')
		errflag = printdi(vars, format);
	else if (*p2 == 'u')
		errflag = printu(vars, format);
	else if (*p2 == 'x' || *p2 == 'X')
		errflag = printx(vars, format, *p2);
	return (errflag);
}

int				print_param(const char *p1, const char *p2, va_list *vars)
{
	int			*format;
	int			errflag;

	errflag = 0;
	if ((!p1 && !p2))
		return (-1);
	if (!*p2)
		return (-1);
	if (*p2 == '%' && *p1 == '%' && p2 - p1 == 1)
		g_cout += write(1, "%", 1);
	else if (*p1 == '%' && ft_strchr(CONV, *p2))
	{
		format = getformat(p1, p2, vars);
		if (getandprintparam(p2, vars, format) == -1)
			errflag = 1;
		free(format);
		format = NULL;
	}
	return (!errflag ? 0 : -1);
}
