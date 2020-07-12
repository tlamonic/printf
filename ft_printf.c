/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:59:22 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/16 23:35:31 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list		vlist;
	int			errflag;

	errflag = 0;
	g_cout = 0;
	if (!format)
		return (-1);
	va_start(vlist, format);
	errflag = parse_format_str(format, &vlist);
	va_end(vlist);
	if (errflag == -1)
		return (-1);
	return (g_cout);
}
