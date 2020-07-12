/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 01:07:49 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/21 01:07:49 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		printend(int *format)
{
	if (format[0] & 1 << 4)
		printspaces(' ', format[1]);
}
