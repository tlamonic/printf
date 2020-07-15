/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:15:31 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 13:18:11 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_to_nbr(char *start, char *end)
{
	int		res;
	int		exp;

	res = 0;
	exp = 1;
	while (end >= start)
	{
		res += (*end - '0') * exp;
		exp *= 10;
		end--;
	}
	return (res);
}
