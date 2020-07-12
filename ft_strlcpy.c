/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:47:43 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/05 19:40:37 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	const char	*start;

	start = src;
	i = size;
	if (i != 0)
	{
		while (--i != 0)
		{
			if ((*dst++ = *src++) == '\0')
				break ;
		}
	}
	if (i == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - start - 1);
}
