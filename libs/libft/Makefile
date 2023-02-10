# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 10:17:12 by sguntepe          #+#    #+#              #
#    Updated: 2023/02/09 21:15:14 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . ! -name "ft_lst*.c" -name "ft_*.c")
BONUS = $(shell find . -name "ft_lst*.c")

CC		= gcc

all: $(NAME)

$(NAME):
	@$(CC) $(FLAG) -c $(SRC)
	@ar rc $(NAME) *.o
bonus:
	@$(CC) $(FLAG) -c $(BONUS)
	@ar rc $(NAME) *.o
clean:
	@/bin/rm -f  *.o *.out
fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
