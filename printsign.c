/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:04:16 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/20 13:04:50 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		printsign(int *format, char *nbr)
{
	if (*nbr == '-')
		ft_putchar_fd('-', 1);
	else if (*nbr != '-' && format[0] & 1 << 3)
		ft_putchar_fd('+', 1);
	else if (*nbr != '-' && format[0] & 1 << 2)
		ft_putchar_fd(' ', 1);
}
