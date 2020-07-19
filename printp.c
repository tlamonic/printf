/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:35:02 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/19 21:11:02 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int			printp(void *ptr, int *format)
{
	char	*arr;
	int		i;
	int		len;

	if (!(arr = sixty((unsigned long long)ptr)))
		return (-1);
	i = 0;
	len = ft_strlen(arr);
	if (!(format[0] & 1 << 1) && format[1] > len)
		printspaces(format[1] - len - 2);
	g_cout += write(1, "0x", 2);
	while (arr[i])
		write(1, &arr[i++], 1);
	if (format[0] & 1 << 1 && format[1] > len)
		printspaces(format[1] - len - 2);
	free(arr);
	return (0);
}
