# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/22 12:25:51 by jgroc-de          #+#    #+#              #
#    Updated: 2018/12/22 12:25:52 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
#CFLAGS= -Wall -Werror -Wextra -I ../libft
CFLAGS= -Wall -Werror -Wextra -g -I ../libft
LIBFT= -L../libft -lft
NAME= ../puissance4
LIB= ../libft/libft.a
.phony: all clean fclean re

SRC= $(wildcard *.c)
OBJ= $(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) connect4.h
	@echo "Compilation de "$(NAME)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBFT)

$(OBJ): connect4.h

$(LIB):
	make -C ../libft

clean:
	@rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
