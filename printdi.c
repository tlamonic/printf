/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:30:22 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/19 20:10:09 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printdi(int i, int *format)
{
	int		size;
	int		tmp;
	void	(*ptr)(size_t);

	if (!format)
		return (-1);
	tmp = 0;
	size = getsize(i);
	if (size < format[2])
	{
		tmp = size;
		size += format[2] - size;
	}
	if ((format[0] & 1 << 1) && !(format[0] & 1) && !format[2])
		ptr = printzero;
	else
		ptr = printspaces;
	if (!(format[0] & 1 << 1) && format[1] > size)
		ptr(format[1] - size);
	if (tmp)
		printzero(format[2] - tmp);
	ft_putnbr(i);
	if (format[0] & 1 << 1 && format[1] > size)
		ptr(format[1] - size);
	return (0);
}
