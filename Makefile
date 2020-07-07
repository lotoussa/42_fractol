# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 21:10:50 by lotoussa          #+#    #+#              #
#    Updated: 2020/03/09 13:48:49 by lotoussa         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -framework OpenGL -framework AppKit

SRC_FILES = main.c \
			color.c \
			drawer.c \
			legend.c \
			hook_tools.c

SRC = $(addprefix srcs/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

HEAD_FILES = fractol.h \
			 libft.h
HEAD = $(addprefix header/, $(HEAD_FILES))

LIBFT = libft/libft.a
MINILIBX = minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

./srcs/%.o: ./srcs/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
