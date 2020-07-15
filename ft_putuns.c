/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:31:53 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 16:35:11 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putuns(unsigned int res)
{
	if (res > 9)
	{
		ft_putuns(res / 10);
		ft_putchar(res % 10 + '0');
	}
	else
		ft_putchar(res + '0');
}
