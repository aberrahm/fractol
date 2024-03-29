# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 03:42:19 by aberrahm          #+#    #+#              #
#    Updated: 2018/01/07 02:25:16 by aberrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang
FLAGS = -Wall -Wextra -Werror

LFT = ./libft/libft.a
LIBS = $(LFT)

LFT_INC = -I ./libft
INC = $(LFT-INC) -I ./
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

SRCS = srcs/create_image.c \
		srcs/main.c \
		srcs/julia.c \
		srcs/mandelbrot.c \
		srcs/burningship.c \
		srcs/zoom.c \
		srcs/event.c \
		srcs/init.c \
		srcs/key.c

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
		$(CC) -c $(FLAGS) $< -o $@

$(NAME) : $(OBJ)
	make -C ./libft
	@echo " "
	@echo "\\033[35m\033[1mLib Ok !\\033[0m"
	@echo " "
	$(CC) $(FLAGS) $(FRAMEWORK) $(LIBS) $(INC) $(OBJ) -o $(NAME)
	@echo " "
	@echo "\\0033[32m\033[1m  Executable created  \\0033[0m"

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	@echo " "
	@echo "\\0033[31m\033[1m  Executable deleted  \\0033[0m"

re: fclean all

.PHONY : all clean fclean re
