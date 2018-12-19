# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 11:41:26 by jgroc-de          #+#    #+#              #
#    Updated: 2018/03/19 15:51:18 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.phony: all clean fclean re

all:
	make -C libft
	make -C connect4

clean:
	make -C libft clean
	make -C connect4 clean

fclean:
	make -C libft fclean
	make -C connect4 fclean

re: fclean all
