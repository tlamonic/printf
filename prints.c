/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:30:37 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 17:30:37 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		prints(int *st, int *format)
{
	char	*str;
	int		len;
	void	(*ptr)(size_t);

	if (!format)
		return (-1);
	ptr = format[0] & 1 ? printzero : printspaces;
	str = (char*)st;
	len = ft_strlen(str);
	if (!st)
		str = "(null)";
	if (format[2] >= 0 && len > format[2])
		len = format[2];
	if (!(format[0] & 1 << 1) && format[1] > len)
		ptr(format[1] - len);
	write(1, str, len);
	if (format[0] & 1 << 1 && format[1] > len)
		ptr(format[1] - len);
	return (0);
}
