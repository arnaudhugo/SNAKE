CC		= gcc
NAME	= snake
SRC		= source/main.c			\
		  source/list.c			\
		  source/count.c		\
		  source/aff_map.c		\
		  source/move.c		\
		  source/readline.c		\
		  libmy/my_putchar.c	\
		  libmy/my_putstr.c
OBJ	= $(SRC:%.c=%.o)
RM	= rm -f

$(NAME):	$(OBJ)
			$(CC) -Wall -Werror -Wpedantic $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:				clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re