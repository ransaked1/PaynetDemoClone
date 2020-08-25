# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/10 18:17:39 by lcernei           #+#    #+#              #
#    Updated: 2016/12/06 15:35:29 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=fillit

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= main.c ft_show_matrix.c show_array.c create_array_from_file.c \
tetra_num.c ft_map.c turn_to_alpha.c ft_put_tetra.c isolate.c \
move_back_map_recursive.c ft_solve.c check_alpha.c del_tetra.c \
check_nalpha.c f_block1.c f_block2.c ft_kek.c f_block3.c f_block4.c \
f_block5.c f_block6.c f_block7.c f_block8.c


OBJ=$(SRC:.c=.o)

$(NAME): 
	@make -C ./libft
	$(CC) $(CFLAGS) -c $(SRC) -I libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ./libft/libft.a

all: $(NAME)

clean:
	@make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
