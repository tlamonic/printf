/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:58:28 by fgavin            #+#    #+#             */
/*   Updated: 2020/07/12 18:52:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LIBFTPRINTF_H
# define FT_PRINTF_LIBFTPRINTF_H
# define CONV "cspdiuxX%"
# define CONV_SIZE 10
# define L_HEX_PREF "0x"
# define U_HEX_PREF "0X"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

size_t				g_cout;
char				getbasechar(unsigned nbr);
int					*getformat(const char *p1, const char *p2, va_list *va);
int					ft_printf(const char *format, ...);
char				*lltoabase(long long nbr, int base);
int					print_param(const char *p1, const char *p2, va_list *va);
int					printchar(int ch, int *format);
void				printend(int *format);
int					printdi(va_list *va, int *format);
int					printp(void *ptr, int *format);
int					printpcnt(int *format);
int					prints(int *str, int *format);
void				printsign(int *format, char *nbr);
void				printstart(char *arr, int *format, int len, int conv);
void				printspaces(char space, size_t count);
int					printu(va_list *va, int *format);
int					printx(va_list *vars, int *format, char p2);
int					parse_format_str(const char *s, va_list *va);
void				reversstr(char *str, size_t len);
long long			setmodifier(va_list *va, int mod);
void				setwidth(char *arrnbr, int *format, int addprec, int len);
unsigned long long	setmunsodifier(va_list *va, int mod);
char				*ulltoabase(unsigned long long nbr, unsigned base);

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_str_to_nbr(char *start, char *end, int sign);
size_t				ft_strlen(char *str);
char				*ft_strchr(const char *s, int c);
int					ft_toupper(int c);
#endif
