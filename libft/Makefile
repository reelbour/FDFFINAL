# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammou- <ahammou-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 14:03:14 by ahammou-          #+#    #+#              #
#    Updated: 2019/05/27 13:56:38 by ahammou-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = ./
FLAG = -Wall -Wextra -Werror
FILE = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp\
	ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat\
	ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi\
	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper\
	ft_tolower ft_memalloc ft_putchar ft_putstr ft_putendl ft_putnbr\
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_memdel\
	ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap\
	ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim\
	ft_strsplit ft_itoa ft_lstnew ft_lstdelone ft_lstdel ft_lstadd \
	ft_lstiter ft_lstmap ft_lstfree ft_isspace ft_lstprint ft_countwords\
	ft_isnegative ft_free_tab_str ft_abs get_next_line ft_lstdestroy ft_lstrev\
	ft_free_tab_void ft_free_tab\

C = $(addsuffix .c, $(FILE))
O = $(addsuffix .o, $(FILE))

RM = rm -f

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c -I $(INCLUDE) $(C)
	ar -rc $(NAME) $(O)
	ranlib $(NAME)

clean:
	$(RM) $(O)

fclean: clean
	$(RM) $(NAME)

re: fclean all
