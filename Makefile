# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 10:02:07 by tmontani          #+#    #+#              #
#    Updated: 2024/06/17 15:21:22 by tmontani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./map_parsing -I./image_related
SRC =    main.c map_parser.c map_utils.c libft.c map_algo.c mlx_init.c mlx_utils.c moves.c


OBJECTS = $(SRC:.c=.o)

all: $(NAME)

libmlx.a:
	$(MAKE) -C mlx

libftprintf.a:
	$(MAKE) -C ft_printf

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lft_printf -lftprintf -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Iminilibx -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

