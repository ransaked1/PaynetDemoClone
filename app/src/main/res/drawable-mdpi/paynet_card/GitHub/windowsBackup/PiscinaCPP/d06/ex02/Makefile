# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 09:46:26 by dbraghis          #+#    #+#              #
#    Updated: 2017/07/29 12:03:21 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = base

CC=clang++

CFLAGS=-Wall -Wextra -Werror -Wno-unused-variable

RM=rm -f

SRC=*.cpp

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean
