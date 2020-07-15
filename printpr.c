/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:00:25 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 17:05:39 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printpr(int *format)
{
	if (!format)
		return (0);
	if (format[1] > 1 && !(format[0] & (1 << 4)))
		while (--format[1] > 0)
			g_cout += write(1, " ", 1);
	write(1, "%", 1);
	if (format[1] > 1 && (format[0] & (1 << 4)))
		while (--format[1] > 0)
			g_cout += write(1, " ", 1);
	return (0);
}
