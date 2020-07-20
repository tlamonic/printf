/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:08:27 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/20 15:08:28 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reversstr(char *str, size_t size)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < size - 1)
	{
		tmp = str[i];
		str[i] = str[size - 1];
		str[size - 1] = tmp;
		size--;
		i++;
	}
}
