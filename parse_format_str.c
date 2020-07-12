/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 01:46:44 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/23 14:22:42 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			parse_format_str(const char *s, va_list *va)
{
	const char	*pmp;

	while (*s)
	{
		pmp = s;
		if (*s == '%')
		{
			s++;
			while (*s && !ft_strchr(CONV, *s))
				s++;
			if (print_param(pmp, s, va) == -1)
				return (-1);
		}
		else
		{
			while (*(s + 1) && *(s + 1) != '%')
				s++;
			g_cout += write(1, pmp, *s ? s - pmp + 1 : s - pmp);
		}
		s += *s ? 1 : 0;
	}
	return (0);
}
