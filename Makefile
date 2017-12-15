# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dleong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 22:50:05 by dleong            #+#    #+#              #
#*   Updated: 2017/09/19 23:43:41 by dleong           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c parse.c draw.c rotate_translate.c error_check.c

OBJ = main.o parse.o draw.o rotate_translate.o error_check.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -o $(NAME) $(OBJ) -L ./minilibx -lmlx -framework OpenGL -framework AppKit -L ./libft -lft
	gcc -Wall -Wextra -Werror -I ./libft -I ./minilibx -c $(SRC)

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: clean fclean re all
