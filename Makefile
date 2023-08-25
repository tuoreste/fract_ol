# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 12:58:18 by otuyishi          #+#    #+#              #
#    Updated: 2023/08/23 21:05:54 by otuyishi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Directories and libraries
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

# Compiler and flags
CC = gcc
CFLAGS =  -Wall -Wextra -Werror -Imlx #-fsanitize=address -g

# Source files and object files
SRC = fractol.c mandelbrot.c julia.c ft_strcmp.c
OBJ = $(SRC:.c=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
