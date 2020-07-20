/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:00:25 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/20 15:10:56 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printpr(int *format)
{
	char c;

	c = format[0] & 1 ? '0' : ' ';
	if (!format)
		return (0);
	if (format[1] > 1 && !(format[0] & (1 << 4)))
		while (--format[1] > 0)
			g_cout += write(1, &c, 1);
	ft_putchar('%');
	if (format[1] > 1 && (format[0] & (1 << 4)))
		while (--format[1] > 0)
			g_cout += write(1, &c, 1);
	return (0);
}
