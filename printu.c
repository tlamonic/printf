/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:39:26 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 16:31:44 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int			printu(unsigned int res, int *format)
{
	int					size;
	void				(*ptr)(size_t);
	char				c;

	if (!format)
		return (-1);
	size = getsize(res);
	if (size < format[2])
	{
		printzero(format[2] - size);
		size = format[2];
	}
	ptr = format[0] & 1 ? printzero : printspaces;
	if (!(format[0] & 1 << 2) && format[1] > size)
		ptr(format[1] - size);
	ft_putuns(res);
	if (format[0] & 1 << 2 && format[1] > size)
		ptr(format[1] - size);
	return (0);
}
