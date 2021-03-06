/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:29:51 by tlamonic          #+#    #+#             */
/*   Updated: 2020/08/06 16:09:17 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LIBFTPRINTF_H
# define FT_PRINTF_LIBFTPRINTF_H
# define CONV "cspdiuxX%"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int				getsize(int n);
void			printspaces(size_t count);
void			printzero(size_t count);
void			reversstr(char *str, size_t size);
char			*ulltoabase(unsigned long long dig, int form);
char			getbasechar(int c);
size_t			g_cout;
int				ft_printf(char *s, ...);
int				*getformat(const char *s1, const char *s2, va_list *vlist);
int				parse_str(const char *s, va_list *vlist);
int				print_param(const char *s1, const char *s2, va_list *vlist);
int				printchar(int ch, int *format);
int				printdi(int i, int *format);
int				prints(int *st, int *format);
int				printu(unsigned int u, int *format);
int				printp(void *ptr, int *format);
int				printpr(int *format);
int				printx(int nbr, int *format, char c);

size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
void			ft_putnbr(int n, int *format);
void			ft_putchar(char c);
void			ft_putuns(unsigned int res);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_to_nbr(char *start, char *end);

#endif
