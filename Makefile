# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 03:42:19 by aberrahm          #+#    #+#              #
#    Updated: 2017/12/09 03:42:22 by aberrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang
FLAGS = -Wall -Wextra -Werror

MLX = ./minilibx_macos/libmlx.a
LFT = ./libft/libft.a
LIBS = $(MLX) $(LFT)

MLX_INC = -I ./minilibx_macos
LFT_INC = -I ./libft
INC = $(LFT-INC) $(MLX_INC) -I ./
FRAMEWORK = -framework OpenGL -framework AppKit

SRCS = srcs/create_image.c \
		srcs/main.c \
		srcs/julia.c \
		srcs/mandelbrot.c \
		srcs/burningship.c \
		srcs/zoom.c \
		srcs/event.c

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
		$(CC) -c $(FLAGS) $< -o $@

$(NAME) : $(OBJ)
	make -C ./libft
	@echo " "
	@echo "\\033[35m\033[1mLib Ok !\\033[0m"
	@echo " "
	make -C ./minilibx_macos
	$(CC) $(FLAGS) $(FRAMEWORK) $(LIBS) $(INC) $(OBJ) -o $(NAME)
	@echo " "
	@echo "\\0033[32m\033[1m  Executable created  \\0033[0m"

clean:
	make clean -C ./libft
	make clean -C ./minilibx_macos
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	@echo " "
	@echo "\\0033[31m\033[1m  Executable deleted  \\0033[0m"

re: fclean all

.PHONY : all clean fclean re
