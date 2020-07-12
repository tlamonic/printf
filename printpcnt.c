/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:10:54 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/18 15:21:44 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			printpcnt(int *format)
{
	char	space;

	if (!format)
		return (-1);
	space = format[0] & 1 ? '0' : ' ';
	if (format[1] > 0 && !(format[0] & 1 << 4))
		printspaces(space, format[1] - 1);
	ft_putchar_fd('%', 1);
	if (format[1] > 0 && (format[0] & 1 << 4))
		printspaces(space, format[1] - 1);
	return (0);
}
