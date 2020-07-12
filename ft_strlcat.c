/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 01:46:07 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/03 14:58:37 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	start;

	start = ft_strlen(dst);
	if (start < size)
		ft_strlcpy(dst + start, src, size - start);
	else
		start = size;
	return (start + ft_strlen((char*)src));
}
