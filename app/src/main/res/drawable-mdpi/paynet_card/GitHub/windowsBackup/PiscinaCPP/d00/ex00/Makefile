# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 08:34:25 by dbraghis          #+#    #+#              #
#    Updated: 2017/07/24 09:13:23 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC=clang++

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=*.cpp

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) megaphone

re: fclean all

.PHONY: clean