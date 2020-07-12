/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printspaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 19:11:36 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/18 20:18:55 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		printspaces(char space, size_t count)
{
	while (count-- != 0)
		g_cout += write(1, &space, 1);
}
