/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:30:12 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/19 19:41:53 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printchar(int ch, int *format)
{
	char	c;

	if (!format)
		return (-1);
	c = (char)ch;
	if (format[1] > 1 && !(format[0] & (1 << 1)))
		while(--format[1] > 0)
			g_cout += write(1, " ", 1);
	g_cout += write(1, &c, 1);
	if (format[1] > 1 && (format[0] & (1 << 1)))
		while (--format[1] > 0)
			g_cout += write(1, " ", 1);
	return (0);
}
