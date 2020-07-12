/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:32:51 by fgavin            #+#    #+#             */
/*   Updated: 2020/07/12 20:26:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			prints(int *s, int *format)
{
	char	*str;
	int		len;

	str = (char*)s;
	if (!format)
		return (-1);
	if (!s)
		str = "(null)";
	len = ft_strlen(str);
	if (format[1] < 0)
	{
		format[0] |= 1u << 4;
		format[1] = -format[1];
	}
	if (format[2] >= 0 && len > format[2])
		len = format[2];
	if (!(format[0] & 1 << 4) && format[1] > len)
		printspaces(' ', format[1] - len);
	write(1, str, len);
	if ((format[0] & 1 << 4) && format[1] > len)
		printspaces(' ', format[1] - len);
	return (0);
}
