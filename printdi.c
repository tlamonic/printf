/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:30:22 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 15:27:48 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printdi(int i, int *format)
{
	int		size;
	void	(*ptr)(size_t);

	if (!format)
		return (-1);
	size = getsize(i);
	if (size < format[2])
	{
		printzero(format[2] - size);
		size = format[2];
	}
	ptr = format[0] & 1 ? printzero : printspaces;
	if (!(format[0] & 1 << 2) && format[1] > size)
		ptr(format[1] - size);
	ft_putnbr(i);
	if (format[0] & 1 << 2 && format[1] > size)
		ptr(format[1] - size);
	return (0);
}
