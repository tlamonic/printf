/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printspaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:30:45 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/25 17:06:38 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printspaces(size_t count)
{
	if (count > 0)
		while (count-- != 0)
			g_cout += write(1, " ", 1);
}
