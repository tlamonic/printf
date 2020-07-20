/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:28:50 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/20 14:46:25 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n, int *format)
{
	if (n == 0 && format[2] == 0)
	{
		g_cout += write(1, " ", 1);
		return ;
	}
	if (n == -2147483648)
	{
		g_cout += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, format);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
