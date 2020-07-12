/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setwidth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 01:09:46 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/22 13:41:56 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		setwidth(char *arrnbr, int *format, int addprec, int len)
{
	format[1] = (len + addprec < format[1]) ? format[1] - addprec - len : 0;
	format[1] -= *arrnbr != '-' && (format[0] & 8 || format[0] & 4) ? 1 : 0;
	format[1] -= (format[0] & 2 && !(len == 1 && *arrnbr == '0')) ? 2 : 0;
	format[1] = format[1] < 0 ? 0 : format[1];
	if (len == 1 && format[2] == 0 && *arrnbr == '0')
	{
		if (format[1])
			format[1]++;
		*arrnbr = 0;
	}
}
