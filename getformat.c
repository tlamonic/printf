/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getformat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:29:30 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 15:23:53 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		getflags(const char *s1, const char *s2)
{
	int		bits;

	bits = 0;
	while (++s1 < s2)
	{
		if (*s1 == '-')
			bits |= 2;
		else if (*s1 == '0' && !(bits & 16) && !ft_isdigit(*(s1 - 1)) &&
				!(*(s1 - 1) == '.' && !ft_isdigit(*(s1 + 1))))
			bits |= 1;
	}
	return (bits);
}

static int		getwidth(const char *s1, const char *s2, va_list *vlist)
{
	int			width;
	const char	*tmp;

	width = 0;
	while (s2 > s1)
	{
		tmp = s2;
		while (ft_isdigit(*s2))
			s2--;
		if (*s2 == '*' && *(s2 - 1) != '.')
		{
			width = va_arg(*vlist, int);
			break ;
		}
		else if (*s2 != '.' && s2 != tmp)
		{
			width = ft_to_nbr((char*)(s2 + 1), (char*)tmp);
			break ;
		}
		s2--;
	}
	return (width);
}

static int		getprescision(const char *s1, const char *s2, va_list *vlist)
{
	int			pres;
	const char	*tmp;

	pres = -1;
	while (s2 > s1)
	{
		tmp = s2;
		while (ft_isdigit(*s2))
			s2--;
		if (*s2 == '.' && !ft_isdigit(*(s2 + 1)))
			return (0);
		if (*s2 == '.' && s2 != tmp)
		{
			pres = ft_to_nbr((char*)(s2 + 1), (char*)tmp);
			break ;
		}
		else if (*s2 == '*' && *(s2 - 1) == '.')
		{
			pres = va_arg(*vlist, int);
			break ;
		}
		s2--;
	}
	return (pres);
}

int				*getformat(const char *s1, const char *s2, va_list *vlist)
{
	int		*res;

	if (!s1 && !s2)
		return (0);
	res = ft_calloc(3, sizeof(int));
	if (!res)
		return (0);
	res[0] = getflags(s1, s2);
	res[1] = getwidth(s1, s2, vlist);
	res[2] = getprescision(s1, s2, vlist);
	return (res);
}
