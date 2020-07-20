/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:23:24 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/20 15:40:01 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				thx_norminette(char *arr, int *format, int len, int tmp)
{
	void	(*ptr)(size_t);

	tmp = 0;
	len = ft_strlen(arr);
	if (format[2] && len < format[2])
	{
		tmp = len;
		len += format[2] - len;
	}
	if (!(format[0] & 1 << 1) && (format[0] & 1) && format[2] == -1)
		ptr = printzero;
	else
		ptr = printspaces;
	if (!(format[0] & 1 << 1) && format[1] > len)
		ptr(format[1] - len);
	if (tmp)
		printzero(format[2] - tmp);
	g_cout += write(1, arr, len);
	if ((format[0] & 1 << 1) && format[1] > len)
		ptr(format[1] - len);
	free(arr);
	return (0);
}

static void		strtoupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int				printx(int nbr, int *format, char c)
{
	char	*arr;
	int		len;
	int		tmp;

	if (!format)
		return (-1);
	if (nbr == 0 && format[2] == 0)
	{
		g_cout += write(1, " ", 1);
		return (0);
	}
	else
		arr = ulltoabase(nbr, 16);
	if (c == 'X')
		strtoupper(arr);
	if (!arr)
		return (-1);
	return (thx_norminette(arr, format, len, tmp));
}
