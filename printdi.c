/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:30:22 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/25 19:51:42 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		width(int *size, int *format, int *i)
{
	int tmp;

	tmp = format[2] > *size ? format[2] : *size;
	if (*i < 0)
		tmp++;
	if ((format[0] & 1) && format[1] > tmp)
	{
		if (*i < 0)
		{
			g_cout += write(1, "-", 1);
			*i *= -1;
			(*size)++;
		}
		printzero(format[1] - tmp);
	}
	else if (format[1] > tmp && !(format[0] & 1 << 1))
		printspaces(format[1] - tmp);
}

static void		pres(int *i, int *format, int *size)
{
	if (*i < 0)
	{
		g_cout += write(1, "-", 1);
		*i *= -1;
		(*size)++;
	}
	if (format[2] > *size)
	{
		printzero(format[2] - getsize(*i));
		*size += format[2] - getsize(*i);
	}
}

int				printdi(int i, int *format)
{
	int		size;
	int		tmp;
	void	(*ptr)(size_t);

	if (!format)
		return (-1);
	size = getsize(i);
	width(&size, format, &i);
	pres(&i, format, &size);
	ft_putnbr(i, format);
	if (format[0] & 1 << 1 && format[1] > size)
		printspaces(format[1] - size);
	return (0);
}
