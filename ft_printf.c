#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
# define CONV "sdx"
int			g_cout;

char		*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			break;
		str++;
	}
	if (*str == c)
		return (str);
	return (0);
}

int			ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}

int			ft_to_nbr(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1 <= s2)
	{
		i = i * 10 + *s1 - '0';
		s1++;
	}
	return (i);
}

int			getwidth(char *s1, char *s2, va_list *vlist)
{
	char	*tmp;
	int		width;

	width = 0;
	while (s2 > s1)
	{
		tmp = s2;
		while (ft_isdigit(*s2))
			s2--;
		if (*s2 == '*' && *(s2 - 1) != '.')
		{
			width = va_arg(*vlist, int);
			break;
		}
		else if (*s2 != '.' && s2 != tmp)
		{
			width = ft_to_nbr((char*)s2 + 1, (char*)tmp);
			break;
		}
		s2--;
	}
	return (width);
}

int			getpres(char *s1, char *s2, va_list *vlist)
{
	int		pres;
	char	*tmp;

	pres = -1;
	while (s2 > s1)
	{
		tmp = s2;
		while (ft_isdigit(*s2))
			s2--;
		if (*s2 == '*' && *(s2 - 1) == '.')
		{
			pres = va_arg(*vlist, int);
			break;
		}
		else if (*s2 == '.' && !ft_isdigit(*(s2 + 1)))
		{
			pres = 0;
			break;
		}
		else if (*s2 == '.' && s2 != tmp)
		{
			pres = ft_to_nbr((char*)s2 + 1, tmp);
			break;
		}
		s2--;
	}
	return (pres);
}

int			*getformat(char *s1, char *s2, va_list *vlist)
{
	int		*format;

	format = malloc(sizeof(int) * 2);
	format[0] = getwidth(s1, s2, vlist);
	format[1] = getpres(s1, s2, vlist);
	return (format);
}

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			prints(int *arr, int *format)
{
	char	*str;
	int		size;
	int		i;

	if (!format)
		return (0);
	i = 0;
	if (!arr)
		str = "(null)";
	else
		str = (char*)arr;
	size = format[1] > -1 ? format[1] : ft_strlen(str);
	while (format[0]-- > size)
		g_cout += write(1, " ", 1);
	while (i < size)
		g_cout += write(1, &str[i++], 1);
	return (0);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int i)
{
	if (i == INT_MIN)
	{
		g_cout += write(1, "-2147483648", 11);
		return ;
	}
	if (i < 0)
		i *= -1;
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
}

int			getsize(int i)
{
	int size;

	size = 0;
	if (i == INT_MIN)
		return (11);
	if (i < 0)
		i *= -1;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		size++;
		i /= 10;
	}
	return (size);
}

char		getbasechar(int c)
{
	if (c >= 10 && c <= 15)
		return (c + 87);
	else if (c >= 0 && c <= 9)
		return (c + '0');
	else
		return ('~');
}

void		reversstr(char *str, int size)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < size - 1)
	{
		tmp = str[i];
		str[i] = str[size - 1];
		str[size - 1] = tmp;
		size--;
		i++;
	}
}

int			printd(int i, int *format)
{
	int		size;
	int		tmp;

	if (!format)
		return (-1);
	if (format[1] == 0 && i == 0)
	{
		while (format[0]-- > 0)
			g_cout += write(1, " ", 1);
		return (0);
	}
	size = format[1] > getsize(i) ? format[1] : getsize(i);
	tmp = i < 0 ? size + 1 : size;
	while (format[0]-- > tmp)
		g_cout += write(1, " ", 1);
	if (i < 0)
		g_cout += write(1, "-", 1);
	while (format[1]-- > getsize(i))
		g_cout += write(1, "0", 1);
	if (i == INT_MIN)
		g_cout += write(1, "2147483648", 10);
	else
		ft_putnbr(i);
	return (0);
}

char		*ulltoabase(int i)
{
	char	*res;
	int		j;
	int		size;

	j = 0;
	size = sizeof(unsigned long long) * 8 + 1;
	res = malloc(sizeof(char) * size);
	while (j < size)
		res[j++] = '\0';
	j = 0;
	while (i > 16)
	{
		res[j++] = getbasechar(i % 16);
		i /= 16;
	}
	res[j] = getbasechar(i);
	reversstr(res, ft_strlen(res));
	return (res);
}

int			printx(int i, int *format)
{
	char	*str;
	int		size;
	int		j;

	if (!format)
		return (-1);
	if (i == 0 && format[1] == 0)
	{
		while (format[0]-- > 0)
			g_cout += write(1, " ", 1);
		return (0);
	}
	j = 0;
	str = ulltoabase(i);
	size = format[1] >= 0 ? format[1] : ft_strlen(str);
	while (format[0]-- > size)
		g_cout += write(1, " ", 1);
	while (size-- > ft_strlen(str))
		g_cout += write(1, "0", 1);
	while (str[j])
		g_cout += write(1, &str[j++], 1);
	free(str);
	return (0);
}

int			getparam(char c, int *format, va_list *vlist)
{
	int		errflag;

	errflag = 0;
	if (c == 's')
		errflag = prints(va_arg(*vlist, int*), format);
	else if (c == 'd')
		errflag = printd(va_arg(*vlist, int), format);
	else if (c == 'x')
		errflag = printx(va_arg(*vlist, int), format);
	return (errflag);
}

int			printparam(char *s1, char *s2, va_list *vlist)
{
	int		errflag;
	int		*format;

	if ((!s1 && !s2) || !*s2)
		return (-1);
	errflag = 0;
	if (*s1 == '%' && *s2 == '%' && s2 - s1 == 1)
		g_cout += write(1, "%", 1);
	else if (*s1 == '%' && ft_strchr(CONV, *s2))
	{
		format = getformat(s1, s2, vlist);
		if (getparam(*s2, format, vlist) == -1)
			errflag = -1;
		free(format);
		format = NULL;
	}
	return (errflag);
}

int			parse_str(char *str, va_list *vlist)
{
	char	*tmp;

	while (*str)
	{
		tmp = str;
		if (*str == '%')
		{
			str++;
			while (!ft_strchr(CONV, *str) && *str)
				str++;
			if (printparam(tmp, str, vlist) == -1)
				return (-1);
		}
		else
		{
			while (*(str + 1) && *(str + 1) != '%')
				str++;
			g_cout += write(1, tmp, *str ? str - tmp + 1 : str - tmp);
		}
		str += *str ? 1 : 0;
	}
	return (0);
}

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
#include <stdio.h>
int main()
{
	ft_printf("%10.3s", NULL);
	printf("%%\n");
	printf("%10.3s", NULL); 
}
