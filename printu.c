/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:44:49 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/22 15:02:41 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				printu(va_list *va, int *format)
{
	unsigned long	res;
	char			*arrnbr;
	int				addprec;
	int				len;

	if (!format)
		return (-1);
	res = setmunsodifier(va, format[3]);
	arrnbr = ulltoabase(res, 10);
	if (!arrnbr)
		return (-1);
	len = ft_strlen(arrnbr);
	addprec = (len < format[2]) ? format[2] - len : 0;
	format[0] &= 17;
	setwidth(arrnbr, format, addprec, len);
	printstart(arrnbr, format, len, 'u');
	if (addprec != 0)
		printspaces('0', addprec);
	ft_putstr_fd(arrnbr, 1);
	printend(format);
	free(arrnbr);
	arrnbr = NULL;
	return (0);
}
