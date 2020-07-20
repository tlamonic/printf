/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoabase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:08:21 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/20 15:08:22 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ulltoabase(unsigned long long dig, int form)
{
	char				*str;
	size_t				size;
	size_t				tmp;

	tmp = 0;
	size = sizeof(long long) * 8 + 1;
	str = (char*)malloc(sizeof(char) * (size));
	if (!str)
		return (0);
	while (tmp < size)
		str[tmp++] = '\0';
	tmp = 0;
	while (dig >= form)
	{
		str[tmp++] = getbasechar(dig % form);
		dig /= form;
	}
	str[tmp] = getbasechar(dig);
	reversstr(str, ft_strlen(str));
	return (str);
}
