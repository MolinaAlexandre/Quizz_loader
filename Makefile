CFLAGS	=	-I./include

SRC	=	src/main.c\
		src/display_help.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	quizz_maker

all:	$(NAME)


$(NAME): $(OBJ)
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) *.gcda *.gcno

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re