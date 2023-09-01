# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 12:58:18 by otuyishi          #+#    #+#              #
#    Updated: 2023/09/01 18:56:50 by otuyishi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CFLAGS := -Wextra -Wall -Werror -g -O3 -funroll-loops -fsanitize=address
LIBMLX := MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a

SRCS := fractol.c mandelbrot.c fractol_utils.c julia.c 
LDFLAGS := -ldl -L $(LIBMLX)/glfw_lib/ -lglfw3 -pthread -lm -fsanitize=address -flto -framework Cocoa -framework OpenGL -framework IOKit
OBJS := $(SRCS:.c=.o) 

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME) && echo "Successful build...!"

MLX:
	chmod 755 setup_libs.sh
	sh setup_libs.sh

rmlib:
	rm -rf MLX42

clean:
	@rm -rf $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all rmlib clean fclean re
