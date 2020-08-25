# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/24 17:45:01 by dbraghis          #+#    #+#              #
#    Updated: 2017/02/08 19:50:05 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

NAMEBASE =	libftprintf

LIB = ./libft/libft.a

FLAGS =	-Wall -Wextra -Werror

INCFLAG =  -I ./includes

SRCDIR = srcs
OBJDIR = obj

SRC_NAME =ft_arguments.c ft_apply_flags.c ft_apply_width.c ft_arg_parse.c ft_check.c ft_modifer.c ft_modifierlh.c ft_parsing.c ft_pointer.c ft_precision.c ft_printf.c ft_printing.c ft_printing1.c ft_put.c ft_put_ptr.c ft_width_wstr.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRCDIR)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJDIR)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	gcc $(FLAGS) -o $@ -c $< $(INCFLAG)

$(LIB):
	make -C libft/ fclean
	make -C libft/

clean:
	rm -f $(OBJ)
	rm -f $(OBJDIR)/*.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: clean fclean