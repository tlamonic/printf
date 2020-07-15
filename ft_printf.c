/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:26:31 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 13:21:24 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char const *s, ...)
{
	va_list	argptr;
	int		errflag;

	if (!s)
		return (-1);
	g_cout = 0;
	errflag = 0;
	va_start(argptr, s);
	errflag = parse_str(s, &argptr);
	va_end(argptr);
	if (errflag == -1)
		return (-1);
	return (g_cout);
}
