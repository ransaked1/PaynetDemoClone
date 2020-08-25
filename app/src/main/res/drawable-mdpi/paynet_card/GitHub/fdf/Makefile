NAME= fdf

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=*.c

OBJ=$(SRC:.c=.o)

$(NAME):
	@make -C ./libft
	$(CC) $(CFLAGS) -c $(SRC) -I libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	@make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
