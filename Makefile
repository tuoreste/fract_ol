# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 12:58:18 by otuyishi          #+#    #+#              #
#    Updated: 2023/08/08 12:59:07 by otuyishi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal

# Directories and libraries
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

# Compiler and flags
CC = gcc
CFLAGS =  -Wall -Wextra -Werror #-fsanitize=address -g

# Source files and object files
SRC = fractal.c
OBJ = $(SRC:.c=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
