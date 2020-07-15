# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 12:36:39 by tlamonic          #+#    #+#              #
#    Updated: 2020/07/15 16:34:11 by tlamonic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a

HEADER = libftprintf.h

SRC_PRINTF = ft_printf.c getformat.c print_param.c printchar.c printdi.c\
			 prints.c printp.c printu.c printspaces.c printzero.c parse_str.c

SRC_LIBFT = ft_calloc.c ft_memset.c ft_putchar.c ft_putnbr.c ft_strchr.c\
			ft_strlen.c ft_isdigit.c getsize.c ft_to_nbr.c ft_putuns.c

SRC = $(SRC_PRINTF) $(SRC_LIBFT)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $@ $?
	ranlib $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(D)

fclean: clean
	@$(RM) $(NAME)

re : fclean all

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ -c $<

.PHONY: all clean fclean re
