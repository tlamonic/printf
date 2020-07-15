/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:26:10 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 12:26:13 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#	define MAX (size_t)~0

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;

	if ((size && MAX / size < count) || (count && MAX / count < size))
		return (NULL);
	arr = malloc(count * size);
	if (!arr)
		return (0);
	ft_memset(arr, '\0', count * size);
	return (arr);
}
