/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoabase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 18:54:54 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/18 19:32:16 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*lltoabase(long long nbr, int base)
{
	char	*arr;
	size_t	len;
	size_t	tmp;
	int		sign;

	tmp = 0;
	len = sizeof(long long) * 8 + 1;
	arr = (char*)malloc(len);
	if (!arr)
		return (NULL);
	ft_bzero(arr, len);
	sign = (nbr >= 0) ? -1 : 1;
	nbr *= sign;
	while (nbr <= -base)
	{
		arr[tmp++] = getbasechar(-(nbr % base));
		nbr /= base;
	}
	arr[tmp] = getbasechar(-nbr);
	if (sign == 1)
		arr[++tmp] = '-';
	reversstr(arr, ft_strlen(arr));
	return (arr);
}
