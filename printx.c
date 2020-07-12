/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:52:56 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/22 13:52:23 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	strtoupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

int			printx(va_list *va, int *format, char p2)
{
	unsigned long	res;
	char			*arrnbr;
	int				addprec;
	int				len;

	if (!format)
		return (-1);
	res = setmunsodifier(va, format[3]);
	arrnbr = ulltoabase(res, 16);
	if (!arrnbr)
		return (-1);
	p2 == 'X' ? strtoupper(arrnbr) : 0;
	len = ft_strlen(arrnbr);
	addprec = (len < format[2]) ? format[2] - len : 0;
	format[0] &= 19;
	setwidth(arrnbr, format, addprec, len);
	printstart(arrnbr, format, len, p2);
	if (addprec != 0)
		printspaces('0', addprec);
	ft_putstr_fd(arrnbr, 1);
	printend(format);
	free(arrnbr);
	arrnbr = NULL;
	return (0);
}
