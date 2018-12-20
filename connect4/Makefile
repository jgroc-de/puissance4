CC=gcc
#CFLAGS= -Wall -Werror -Wextra -I ../libft
CFLAGS= -Wall -Werror -Wextra -fsanitize=address -g -I ../libft
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
