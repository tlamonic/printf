/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoabase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 03:05:45 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/18 19:07:25 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ulltoabase(unsigned long long nbr, unsigned base)
{
	char	*arr;
	size_t	len;
	size_t	tmp;

	tmp = 0;
	len = sizeof(long long) * 8 + 1;
	arr = (char*)malloc(len);
	if (!arr)
		return (NULL);
	while (tmp < len)
		arr[tmp++] = 0;
	tmp = 0;
	while (nbr >= base)
	{
		arr[tmp++] = getbasechar(nbr % base);
		nbr /= base;
	}
	arr[tmp] = getbasechar(nbr);
	reversstr(arr, ft_strlen(arr));
	return (arr);
}
