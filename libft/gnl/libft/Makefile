# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:47:01 by jgroc-de          #+#    #+#              #
#    Updated: 2017/12/25 18:48:32 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Werror -Wall -Wextra -I includes
AR= ar
ARFLAGS= rcs
NAME= libft.a
.suffixes:
.phony: all clean fclean re
OBJ= $(SRC:.c=.o)

SRC=	./ft_putchar.c\
		./ft_del.c\
		./ft_atoi.c\
		./ft_isprime.c\
		./ft_itoa.c\
		./ft_max.c\
		./ft_min.c\
		./ft_nextprime.c\
		./ft_pow.c\
		./ft_putendl_fd.c\
		./ft_putstr_fd.c\
		./ft_qsort.c\
		./ft_sqrt.c\
		./ft_strchr.c\
		./ft_strequ.c\
		./ft_strdup.c\
		./ft_strndup.c\
		./ft_striteri.c\
		./ft_strjoin.c\
		./ft_strmap.c\
		./ft_strmapi.c\
		./ft_strnequ.c\
		./ft_strnew.c\
		./ft_strnstr.c\
		./ft_strrchr.c\
		./ft_strstr.c\
		./ft_strsub.c\
		./ft_strtrim.c\
		./ft_abs.c\
		./ft_bzero.c\
		./ft_isalnum.c\
		./ft_isalpha.c\
		./ft_isdigit.c\
		./ft_islower.c\
		./ft_isprint.c\
		./ft_isupper.c\
		./ft_memdel.c\
		./ft_putchar.c\
		./ft_putchar_fd.c\
		./ft_putendl.c\
		./ft_putnbr.c\
		./ft_putnbr_fd.c\
		./ft_putstr.c\
		./ft_strcat.c\
		./ft_strclr.c\
		./ft_strcmp.c\
		./ft_strcpy.c\
		./ft_strdel.c\
		./ft_striter.c\
		./ft_strlen.c\
		./ft_strncat.c\
		./ft_strncmp.c\
		./ft_strncpy.c\
		./ft_swap.c\
		./ft_toupper.c\
		./ft_isascii.c\
		./ft_tolower.c\
		./ft_strlcat.c\
		./ft_strsplit.c\
		./ft_memalloc.c\
		./ft_memccpy.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_memcpy.c\
		./ft_memmove.c\
		./ft_memset.c\
		./ft_lstadd.c\
		./ft_lstiter.c\
		./ft_lstnew.c\
		./ft_lstmap.c\
		./ft_lstdel.c\
		./ft_lstdelone.c\
		./ft_lst_insert.c\
		./ft_lstdel_relink.c\
		./ft_strnew_ch.c

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
