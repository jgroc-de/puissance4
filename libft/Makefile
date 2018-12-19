# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 11:23:09 by jgroc-de          #+#    #+#              #
#    Updated: 2018/02/06 11:56:01 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
#CFLAGS= -Wall -Werror -Wextra -I .
CFLAGS= -Wall -Werror -Wextra -fsanitize=address -I .
AR= ar
ARFLAGS= rcs
NAME= libft.a
.phony: all clean fclean re
SRC=$(wildcard *.c) $(wildcard GNL/*.c) $(wildcard printf/*.c)
OBJ=$(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) libft.h
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	@rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
