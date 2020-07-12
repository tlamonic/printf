# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgavin <fgavin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/10 19:00:35 by fgavin            #+#    #+#              #
#    Updated: 2020/07/12 18:53:03 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
FLAG = -Wall -Werror -Wextra
RM = rm -f

NAME = libftprintf.a
HEADER = libftprintf.h

SRC_PRINTF = ft_printf.c\
	parse_format_str.c\
	getbasechar.c\
	getformat.c\
	lltoabase.c\
	print_param.c\
	printchar.c\
	printend.c\
	printdi.c\
	printp.c\
	printpcnt.c\
	prints.c\
	printsign.c\
	printspaces.c\
	printstart.c\
	printu.c\
	printx.c\
	reversstr.c\
	setmodifier.c\
	setwidth.c\
	setmunsodifier.c\
	ulltoabase.c\

SRC_LIBFT = ft_strchr.c\
	ft_isalpha.c\
	ft_str_to_nbr.c\
	ft_isdigit.c\
	ft_calloc.c\
	ft_bzero.c\
	ft_memchr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_toupper.c

SRC = $(SRC_PRINTF) $(SRC_LIBFT)

OBJ = $(SRC:.c=.o)

D = $(SRC:.c=.d)

BONUS = .bonus

#Variables contents colours for 'echo'
BG = \033[1;32m
NR = \033[0;31m
DF = \033[0m

all: $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $@ $?
	@ranlib $(NAME)
	@echo "$(BG)creating $(NAME)$(DEF)"
bonus: $(BONUS)
$(BONUS): $(NAME)
	@touch $<
	@touch $@
	@echo "$(BG)creating bonus part $(NAME)$(DEF)"
clean:
	@$(RM) $(OBJ)
	@$(RM) $(D)
	@echo "$(NR)removing object files$(DEF)"
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@echo "$(NR)removing $(NAME)$(DEF)"
re : fclean all
%.o: %.c
	@$(CC) $(FLAGS) -c -MD $<
include $(wildcard $(D))
.PHONY: all bonus clean fclean re
