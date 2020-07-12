/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:31:38 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/22 13:47:50 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				printdi(va_list *va, int *format)
{
	char		*arrnbr;
	int			len;
	int			hassign;
	int			addprec;

	if (!format)
		return (-1);
	arrnbr = lltoabase(setmodifier(va, format[3]), 10);
	if (!arrnbr)
		return (-1);
	len = ft_strlen(arrnbr);
	hassign = *arrnbr == '-' ? 1 : 0;
	addprec = (len < format[2]) ? format[2] - len + hassign : 0;
	setwidth(arrnbr, format, addprec, len);
	printstart(arrnbr, format, len, 'd');
	if (addprec != 0)
		printspaces('0', addprec);
	if (*arrnbr == '-')
		ft_putstr_fd(arrnbr + 1, 1);
	else
		ft_putstr_fd(arrnbr, 1);
	printend(format);
	free(arrnbr);
	arrnbr = NULL;
	return (0);
}
