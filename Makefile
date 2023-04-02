CFLAGS	=	-I./include

SRC	=	src/main.c\
		src/display_help.c\
		src/player.c\
		src/error_handling.c\
		src/init_quizz.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	quizz_loader

all:	$(NAME)


$(NAME): $(OBJ)
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) *.gcda *.gcno

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re