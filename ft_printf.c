#include "libftprintf.h"

int			ft_printf(char *str, ...)
{
	va_list	vlist;
	int		errflag;

	if (!str)
		return (-1);
	g_cout = 0;
	va_start(vlist, str);
	errflag = parse_str(str, &vlist);
	va_end(vlist);
	if (errflag == -1)
		return (-1);
	return (g_cout);
}
