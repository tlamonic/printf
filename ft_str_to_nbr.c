/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 12:02:49 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/16 12:02:49 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_str_to_nbr(char *start, char *end, int sign)
{
	long	res;
	long	exp;
	long	prev;
	char	*ptr;

	exp = 1 * sign;
	res = 0;
	ptr = end;
	while (end >= start)
	{
		prev = res;
		res += (*end - '0') * exp;
		if (prev != res % exp && ptr != end)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		exp *= 10;
		end--;
	}
	return ((int)res);
}
