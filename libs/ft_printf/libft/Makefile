NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "*.c")

CC		= gcc

all: $(NAME)

$(NAME):
	@$(CC) $(FLAG) -c $(SRC)
	@ar rc $(NAME) *.o
clean:
	@/bin/rm -f  *.o *.out
fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re