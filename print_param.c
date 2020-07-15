/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:30:06 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 17:00:16 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	getparam(const char *s2, va_list *vlist, int *format)
{
	int		errflag;

	errflag = 0;
	if (*s2 == 'c')
		errflag = printchar(va_arg(*vlist, int), format);
	else if (*s2 == 's')
		errflag = prints(va_arg(*vlist, int*), format);
	else if (*s2 == 'p')
		errflag = printp(va_arg(*vlist, void*), format);
	else if (*s2 == 'd' || *s2 == 'i')
		errflag = printdi(va_arg(*vlist, int), format);
	else if (*s2 == 'u')
		errflag = printu(va_arg(*vlist, unsigned int), format);
//	else if (*s2 == 'x' || *s2 == 'X')
//		errflag = printx(vlist, format);
	else if (*s2 == '%')
		errflag = printpr(format);
	return (errflag);
}

int			print_param(const char *s1, const char *s2, va_list *vlist)
{
	int		errflag;
	int		*format;

	if (!s1 && !s2)
		return (-1);
	if (!*s2)
		return (-1);
	errflag = 0;
	if (*s2 == '%' && *s1 == '%' && s2 - s1 == 1)
		g_cout += write(1, "%", 1);
	else if (*s1 == '%' && ft_strchr(CONV, *s2))
	{
		format = getformat(s1, s2, vlist);
		if (getparam(s2, vlist, format) == -1)
			errflag = -1;
		free(format);
		format = NULL;
	}
	return (errflag);
}
