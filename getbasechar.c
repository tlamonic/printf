/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbasechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 18:43:41 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/18 18:47:37 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	getbasechar(unsigned nbr)
{
	if (nbr >= 0 && nbr <= 9)
		return ('0' + nbr);
	else if (nbr >= 10 && nbr <= 15)
		return (87 + nbr);
	else
		return ('~');
}
