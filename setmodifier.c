/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmodifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:01:11 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/20 13:01:59 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	setmodifier(va_list *va, int mod)
{
	if (mod & 1 << 3)
		return (va_arg(*va, long long));
	else if (mod & 1 << 2)
		return (va_arg(*va, long));
	else if (mod & 1 << 1)
		return ((short)(va_arg(*va, int)));
	else if (mod & 1)
		return ((char)(va_arg(*va, int)));
	else
		return ((va_arg(*va, int)));
}
