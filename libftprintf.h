/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:29:51 by tlamonic          #+#    #+#             */
/*   Updated: 2020/07/15 16:35:34 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LIBFTPRINTF_H
# define FT_PRINTF_LIBFTPRINTF_H
# define CONV "cspdiuxX%"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

size_t 			g_cout;
void			printspaces(size_t count);
void			printzero(size_t count);
int				ft_printf(char const *s, ...);
int				*getformat(const char *s1, const char *s2, va_list *vlist);
int 			getsize(int n);
int				parse_str(const char *s, va_list *vlist);
int				print_param(const char *s1, const char *s2, va_list *vlist);
int				printchar(int ch, int *format);
int				printdi(int i, int *format);
int				prints(int *st, int *format);
int				printu(unsigned int u, int *format);
int				printp(void *ptr, int *format);

size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putuns(unsigned int res);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_to_nbr(char *start, char *end);

#endif
