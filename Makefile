# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreynaer <jreynaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 12:21:01 by jreynaer          #+#    #+#              #
#    Updated: 2019/05/17 12:57:25 by ahammou-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
OBJ = src/algo.o src/init_map.o src/main.o src/render.o src/validation.o 
SRC = src/algo.c src/init_map.c src/main.c src/render.c src/validation.c \
	  libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -L ./mlx -lmlx  -framework OpenGl -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
