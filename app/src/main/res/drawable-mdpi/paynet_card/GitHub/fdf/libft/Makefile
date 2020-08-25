# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/24 17:45:01 by dbraghis          #+#    #+#              #
#    Updated: 2017/02/08 20:26:15 by eceban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRC=ft_strcat.c ft_strlen.c ft_strncat.c ft_bzero.c ft_memalloc.c ft_memccpy.c ft_min.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_strcat.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncpy.c ft_tolower.c ft_toupper.c ft_strcpy.c ft_strlcat.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strstr.c ft_strnstr.c ft_strncmp.c ft_lstnew.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putstr.c ft_strclr.c ft_strdel.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnew.c ft_strcmp.c ft_strchr.c ft_strrchr.c ft_atoi.c ft_strequ.c ft_strnequ.c ft_putnbr.c ft_strsub.c ft_putnbr_fd.c ft_putstr_fd.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_strsplit.c ft_lstiter.c ft_strtrim.c ft_lstmap.c ft_itoa.c ft_ncuvinte.c ft_lcuvint.c ft_stringlen.c ft_digits.c ft_fillstring.c ft_lltoa.c ft_wcharlen.c ft_wstrdup.c ft_wstrjoin.c ft_wstrlen.c ft_wstrsub.c ft_itoa_base.c ft_realloc.c

OBJ=$(SRC:.c=.o)

$(NAME): libft.h
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
