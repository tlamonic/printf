/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmunsodifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 01:42:32 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/22 15:05:05 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long	setmunsodifier(va_list *va, int mod)
{
	if (mod & 1 << 3)
		return (va_arg(*va, unsigned long long));
	else if (mod & 1 << 2)
		return (va_arg(*va, unsigned long));
	else if (mod & 1 << 1)
		return ((unsigned short)(va_arg(*va, unsigned int)));
	else if (mod & 1)
		return ((unsigned char)(va_arg(*va, unsigned int)));
	else
		return ((va_arg(*va, unsigned int)));
}
