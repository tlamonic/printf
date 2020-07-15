/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:30:12 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 12:30:13 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printchar(int ch, int *format)
{
	char c;

	c = (char)c;
	if (format[1] > 1 && !(format[0] & (1 << 4)))
	{
		while (--format[1] > 0)
			g_cout += write(1, " ", 1);
	}
	write(1, &c, 1);
	if (format[1] > 1 && (format[0] & (1 << 4)))
	{
		while (--format[1] > 0)
			g_cout += write(1, " ", 1);
	}
	return (0);
}
