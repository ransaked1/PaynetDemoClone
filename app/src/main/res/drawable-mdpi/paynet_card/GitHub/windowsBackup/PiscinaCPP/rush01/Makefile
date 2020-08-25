
NAME = GKrellM

CC = clang++
# CFLAGS = -Wall -Wextra -Werror

CFLAGS  = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj

RM=rm -rf

SRC = src/*.cpp

OBJ = obj/*.o

all: $(NAME)
	@echo "MAKE ALL IS DONE"

$(NAME):
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $(SRC)
	@mv *.o $(OBJDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lncurses

clean:
	@$(RM) $(OBJDIR)
	@echo "MAKE CLEAN IS DONE"

fclean:
	@$(RM) $(OBJDIR)
	@$(RM) $(NAME)
	@echo "MAKE FCLEAN IS DONE"	

re:
	@$(RM) $(OBJDIR)
	@$(RM) $(NAME)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $(SRC)
	@mv *.o $(OBJDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lncurses
	@echo "MAKE RE IS DONE"

.PHONY: clean fclean
