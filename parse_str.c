/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:29:59 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 12:30:00 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parse_str(const char *s, va_list *vlist)
{
	const char *tmp;

	while (*s)
	{
		tmp = s;
		if (*s == '%')
		{
			s++;
			while (!ft_strchr(CONV, *s) && *s)
				s++;
			if (print_param(tmp, s, vlist) == -1)
				return (-1);
		}
		else
		{
			while (*(s + 1) && *(s + 1) != '%')
				s++;
			g_cout += write(1, tmp, *s ? s - tmp + 1 : s - tmp);
		}
		s += *s ? 1 : 0;
	}
	return (0);
}
