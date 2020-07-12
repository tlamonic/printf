/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 15:09:53 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/25 19:38:07 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			printchar(int ch, int *format)
{
	char	c;
	wchar_t ct;

	c = (char)ch;
	ct = (wchar_t)ch;
	if (!format)
		return (-1);
	if (format[1] > 1 && !(format[0] & (1 << 4)))
	{
		while (--format[1] > 0)
			g_cout += write(1, " ", 1);
	}
	g_cout += (format[3] & 1u << 2) ? write(1, &ct, 1) :
			write(1, &c, 1);
	if (format[1] > 1 && (format[0] & (1 << 4)))
	{
		while (--format[1] > 0)
			g_cout += write(1, " ", 1);
	}
	return (0);
}
