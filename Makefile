# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 10:02:07 by tmontani          #+#    #+#              #
#    Updated: 2024/05/03 13:40:02 by tmontani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = $(addprefix src/, main.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)
PRINTF_SRC = $(addprefix ft_printf/, ft_printf.c ft_printf_utils.c)
OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):$(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	gcc $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

debug: $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	gcc $(CCFLAGS) -fsanitize=address $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

mlx:
	@$(MAKE) re -C mlx/

re: fclean all