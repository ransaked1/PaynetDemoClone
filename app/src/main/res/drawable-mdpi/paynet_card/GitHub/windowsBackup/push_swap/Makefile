
NAME1 = checker
NAME2 = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR1 = csrcs
SRCDIR2 = pscrcs
OBJDIR1 = obj1
OBJDIR2 = obj2

INCFLAG = -I ./includes

RM=rm -rf

SRC1 = csrcs/*.c
SRC2 = psrcs/*.c

OBJ1 = obj1/*.o
OBJ2 = obj2/*.o

all: $(NAME1) $(NAME2)
	@echo "MAKE ALL IS DONE"

$(NAME1):
	@make -C ./libft
	@mkdir -p $(OBJDIR1)
	@$(CC) $(CFLAGS) -c $(SRC1) -I libft/
	@mv *.o $(OBJDIR1)
	@$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) ./libft/libft.a

$(NAME2):
	@mkdir -p $(OBJDIR2)
	@$(CC) $(CFLAGS) -c $(SRC2) -I libft/
	@mv *.o $(OBJDIR2)
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) ./libft/libft.a

clean:
	@make clean -C ./libft
	@$(RM) $(OBJDIR1)
	@$(RM) $(OBJDIR2)
	@echo "MAKE CLEAN IS DONE"

fclean:
	@make fclean -C ./libft
	@$(RM) $(OBJDIR1)
	@$(RM) $(OBJDIR2)
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)
	@echo "MAKE FCLEAN IS DONE"	

re:
	@make fclean -C ./libft
	@$(RM) $(OBJDIR1)
	@$(RM) $(OBJDIR2)
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)
		@make -C ./libft
	@mkdir -p $(OBJDIR1)
	@$(CC) $(CFLAGS) -c $(SRC1) -I libft/
	@mv *.o $(OBJDIR1)
	@$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) ./libft/libft.a
		@mkdir -p $(OBJDIR2)
	@$(CC) $(CFLAGS) -c $(SRC2) -I libft/
	@mv *.o $(OBJDIR2)
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) ./libft/libft.a
	@echo "MAKE RE IS DONE"

.PHONY: clean fclean
