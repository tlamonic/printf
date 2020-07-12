/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 18:45:32 by fgavin            #+#    #+#             */
/*   Updated: 2020/05/18 18:47:37 by fgavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reversstr(char *str, size_t len)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < len - 1)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		len--;
		i++;
	}
}
