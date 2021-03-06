# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/19 08:31:57 by ahammou-          #+#    #+#              #
#    Updated: 2019/06/05 11:44:17 by ahammou-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
OBJ = src/init_map.o src/main.o src/render.o src/validation.o src/keymap.o
SRC = src/init_map.c src/main.c src/render.c src/validation.c src/keymap.c\
	  src/draw.c src/menu.c libft/libft.a
FLAGS =  -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	make re -C libft/
	make re -C mlx/
	gcc -o $(NAME) $(FLAGS) $(SRC) -L ./mlx -lmlx  -framework OpenGl -framework AppKit

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all $(NAME)

.PHONY: all clean fclean re
