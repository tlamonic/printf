/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:29:02 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 12:29:03 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			break ;
		str++;
	}
	if (*str == c)
		return ((char*)str);
	else
		return (0);
}
