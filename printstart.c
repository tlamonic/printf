/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 01:06:20 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/22 15:00:39 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	printprefix(char *str, int len, int *format, int p2)
{
	if (*str == 0 || (len == 1 && *str == '0'))
		return ;
	else if (format[0] & 1U << 1)
	{
		if (p2 == 'X')
			ft_putstr_fd(U_HEX_PREF, 1);
		else
			ft_putstr_fd(L_HEX_PREF, 1);
	}
}

void		printstart(char *arr, int *format, int len, int conv)
{
	if (!(format[0] & 1 << 4))
	{
		if (!(format[0] & 1) || (format[0] & 1 && format[2] > 0))
		{
			printspaces(' ', format[1]);
			printprefix(arr, len, format, conv);
		}
		printsign(format, arr);
		if (format[0] & 1 && format[2] <= 0)
		{
			printprefix(arr, len, format, conv);
			printspaces('0', format[1]);
		}
	}
	else
	{
		printsign(format, arr);
		printprefix(arr, len, format, conv);
	}
}
