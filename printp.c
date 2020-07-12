/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 12:04:44 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/20 17:06:14 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			printp(void *ptr, int *format)
{
	char	*arr;
	int		i;
	int		len;

	len =
	i = 0;
	if (!format)
		return (-1);
	arr = ulltoabase((unsigned long long)ptr, 16);
	len = ft_strlen(arr);
	if (!(format[0] & 1 << 4) && (format[1] > len) && format[1] > 3)
		printspaces(' ', format[1] - len - 2);
	g_cout += write(1, L_HEX_PREF, 2);
	if (len)
		ft_putstr_fd(arr, 1);
	else
		ft_putchar_fd('0', 1);
	if ((format[0] & 1 << 4) && (format[1] > len))
		printspaces(' ', format[1] - len - 2);
	free(arr);
	arr = NULL;
	return (0);
}
