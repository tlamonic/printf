/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:35:02 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/17 23:30:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int			printp(void *ptr, int *format)
{
	char	*arr;
	int		diff;
	int		size;

	if (!(arr = sixty((unsigned long long)ptr)))
		return (-1);
	size = ft_strlen(arr);
	write(1, "0x", 2);
	if (size < 12)
	{
		diff = 12 - size;
		while (diff--)
			write(1, "0", 1);
	}
	while (size-- > 0)
		write(1, &arr[size], 1);
	free(arr);
	return (0);
}
