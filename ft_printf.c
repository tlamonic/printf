#include "libftprintf.h"

static char    *ft_strchr(char *str, char c)
{
    int i;

    if (!str)
        return (0);
    i = -1;
    while (str[++i])
    {
        if (str[i] == c)
            break;
    }
    if (str[i] == c)
        return (&str[i]);
    return (0);
}

static int     ft_to_nbr(char *start, char *end)
{
    int     res;

    res = 0;
    while (end >= start)
    {
        res = res * 10 + (*start - '0');
        start++;
    }
    return (res);
}

static int     ft_isdigit(char c)
{
    return ((c >= '0' && c <= '9'));
}

static int     getsize(int i)
{
    int size;

    size = 0;
    if (i == INT_MIN)
        return (11);
    if (i == 0)
        return (1);
    if (i < 0)
    {
        size++;
        i *= -1;
    }
    while (i)
    {
        size++;
        i /= 10;
    }
    return (size);
}

static size_t  ft_strlen(char *str)
{
    size_t size;

    size = 0;
    while (str[size])
        size++;
    return (size);
}

static void     ft_putchar(char c)
{
    g_cout += write(1, &c, 1);
}

static void    ft_putnbr(int i)
{
    if (i == INT_MIN)
    {
        g_cout += write(1, "-2147483648", 11);
        return ;
    }
    if (i < 0)
    {
        i *= -1;
        g_cout += write(1, "-", 1);
    }
    if (i > 9)
    {
        ft_putnbr(i / 10);
        ft_putchar((i % 10) + '0');
    }
    else
        ft_putchar(i + '0');
}

static char     getbasechar(int c)
{
    if (c > 9 && c < 16)
        return (c + 87);
    else if (c >= 0 && c < 10)
        return (c + '0');
    else
        return ('~');
}

static void     reversstr(char *str, size_t size)
{
    size_t i;
    char    tmp;

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

static char     *ulltoabase(int i, int form)
{
    char *str;
    size_t size;
    size_t tmp;

    tmp = 0;
    size = sizeof(long long) * 8 + 1;
    if (!(str = (char*)malloc(sizeof(char) * size)))
        return 0;
    while (tmp < size)
        str[tmp++] = '\0';
    tmp = 0;
    while (i >= form)
    {
        str[tmp++] = getbasechar(i % form);
        i /= form;
    }
    str[tmp] = getbasechar(i);
    reversstr(str, ft_strlen(str));
    return (str);
}

static int     printx(unsigned int i, int *format, char c)
{
    char    *res;
    int     size;
    int     j;

    if (!format)
        return (-1);
    j = -1;
    if (i == 0 && format[1] == 0)
    {
        while (format[0]--)
            g_cout += write(1, " ", 1);
        return (0);
    }
    if (!(res = ulltoabase(i, 16)))
        return (-1);
    size = format[1] >= 0 ? format[1] : ft_strlen(res);
    while (format[0]-- > size)
        g_cout += write(1, " ", 1);
    while (size-- > ft_strlen(res))
        g_cout += write(1, "0", 1);
    while (++j < ft_strlen(res))
        ft_putchar(res[j]);
    free(res);
    return (0);
}

static int     prints(int *arr, int *format)
{
    char    *str;
    int     size;
    int     i;

    if (!format)
        return (-1);
    str = (char*)arr;
    i = -1;
    size = format[1] >= 0 ? format[1] : ft_strlen(arr);
    while (format[0]-- > size)
        g_cout += write(1, " ", 1);
    while (++i < size)
        ft_putchar(str[i]);
    return (0);
}

static int     printd(int i, int *format)
{
    int size;

    if (!format)
        return (-1);
    size = getsize(i);
    while (format[0]-- > format[1])
        g_cout += write(1, " ", 1);
    while (format[1]-- > size)
        g_cout += write(1, "0", 1);
    ft_putnbr(i);
    return (0);
}

static int     getwidth(char *str, char *str2, va_list *vlist)
{
    char    *tmp;
    int     width;

    width = 0;
    while (str2 > str)
    {
        tmp = str2;
        while (ft_isdigit(*str2))
            str2--;
        if (*str2 == '*' && *(str2 - 1) != '-')
        {
            width = va_arg(*vlist, int);
            break;
        }
        else if (*str2 != '.' && str2 != tmp)
        {
            width = ft_to_nbr((char*)str2 + 1, (char*)tmp);
            break;
        }
        str2--;
    }
    return (width);
}

static int     getpres(char *s1, char *s2, va_list *vlist)
{
    int     pres;
    char    *tmp;

    pres = -1;
    while (s2 > s1)
    {
        tmp = s2;
        while (ft_isdigit(*s2))
            s2--;
        if (*s2 == '.' && !ft_isdigit(*(s2 + 1)))
            return (0);
        if (*s2 == '*' && *(s2 - 1) == '.')
        {
            pres = va_arg(*vlist, int);
            break;
        }
        else if (*s2 == '.' && s2 != tmp)
        {
            pres = ft_to_nbr((char*)s2 + 1, (char*)tmp);
            break;
        }
        s2--;
    }
    return (pres);
}

static int     *getformat(char *s1, char *s2, va_list *vlist)
{
    int *format;

    if (!s2 && !s2)
        return (0);
    if (!(format = malloc(sizeof(int) * 2)))
        return (0);
    format[0] = getwidth(s1, s2, vlist);
    format[1] = getpres(s1, s2, vlist);
    return (format);
}

static int     getparam(char *str, int *format, va_list *vlist)
{
    int errflag;

    errflag = 0;
    if (*str == 'd' || *str == 'i')
        errflag = printd(va_arg(*vlist, int), format);
        else if (*str == 'x')
        errflag = printx(va_arg(*vlist, int), format, *str);
    else if (*str == 's')
        errflag = prints(va_arg(*vlist, int*), format);
    return (errflag);
}

static int             print_param(char *str, char *tmp, va_list *vlist)
{
    int errflag;
    int *format;

    if (!str && !tmp)
        return (-1);
    if (!*tmp)
        return (-1);
    errflag = 0;
    if (*tmp == '%' && *str == '%' && tmp - str == 1)
        g_cout += write(1, "%", 1);
    else if (*str == '%' && ft_strchr(CONV, *tmp))
    {
        format = getformat(str, tmp, vlist);
        if (getparam(tmp, format, vlist) == -1)
            errflag = -1;
        free(format);
        format = NULL;
    }
    return (errflag);
}

static int     parse_str(char *str, va_list *vlist)
{
    char    *tmp;

    while (*str)
    {
        tmp = str;
        if (*str == '%')
        {
            str++;
            while (!ft_strchr(CONV, *str) && *str)
                str++;
            if (print_param(tmp, str, vlist) == -1)
                return (-1);
        }
        else
        {
            while (*(str + 1) && *(str + 1) != '%')
                str++;
            g_cout += write(1, tmp, *str ? str - tmp + 1: str - tmp);
        }
        str += *str ? 1 : 0;
    }
    return 0;
}

int     ft_printf(char *str, ...)
{
    int         errflag;
    va_list     argptr;

    if (!str)
        return (-1);
    errflag = 0;
    g_cout = 0;
    va_start(argptr, str);
    errflag = parse_str(str, &argptr);
    va_end(argptr);
    if (errflag == -1)
        return (-1);
    return (g_cout);
}

int main()
{
    ft_printf("count of symbols is %d\n\n\n\n\n", ft_printf("Hello World! %10.6d\n\n\n", 123));
    printf("count of symbols is %d\n\n\n\n\n", printf("Hello World! %10.6d\n\n\n", 123));
    return 0;
}
