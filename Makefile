# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/19 08:31:57 by ahammou-          #+#    #+#              #
#    Updated: 2019/05/30 16:20:27 by ahammou-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
OBJ = src/init_map.o src/main.o src/render.o src/validation.o src/keymap.o
SRC = src/init_map.c src/main.c src/render.c src/validation.c src/keymap.c\
	  src/draw.c src/menu.c libft/libft.a
FLAGS =  -Wall -Wextra -Werror #-fsanitize=address
all: $(NAME)

$(NAME):
	make re -C libft/
	make re -C mlx/
	gcc -o $(NAME) $(FLAGS) $(SRC) -L ./mlx -lmlx  -framework OpenGl -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all $(NAME)

.PHONY: all clean fclean re
