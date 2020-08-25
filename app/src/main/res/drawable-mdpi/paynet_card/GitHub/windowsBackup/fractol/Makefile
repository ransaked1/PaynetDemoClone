# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/13 17:05:37 by dbraghis          #+#    #+#              #
#    Updated: 2017/05/13 17:12:11 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
FLAGS	= -Wall -Wextra -Werror

SRC		=	main.c \
			julia.c \
			mandelbrot.c \
			burning_ship.c \
			gen_fn.c \
			print.c \
			color.c \
			khooks.c \
			mhooks.c
OBJ		= $(SRC:.c=.o)

$(NAME):
		@echo "Libft...\t\c" 
		@make -C libft/ fclean && make -C libft/
		@echo "\x1B[01;90m[DONE]\x1B[0m"
		@echo "Compilation...\t\c" 
		@gcc $(FLAGS) -o $(NAME) $(SRC) libft/libft.a \
			-lmlx -framework OpenGL -framework AppKit
		@echo "\x1B[01;90m[DONE]\x1B[0m"

all:	$(NAME)

clean:
		@make -C libft/ clean
		@rm -f $(OBJ)

fclean:	clean
		@echo "Cleaning...\t\c"
		@make -C libft/ fclean
		@rm -f $(NAME)
		@rm -f *.a
		@echo "\x1B[01;90m[DONE]\x1B[0m"

re: fclean all
