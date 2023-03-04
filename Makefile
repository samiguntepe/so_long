# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 23:59:38 by sguntepe          #+#    #+#              #
#    Updated: 2023/03/04 22:59:02 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc -g
MINILIBX	= libs/minilibx/libmlx.a
NAME 		= so_long	
FLAGS		= -Wall -Wextra -Werror 
OFLAGS		= -framework OpenGL -framework AppKit
SRCS 		= $(shell find main -name "*.c")
OBJS 		= $(SRCS:.c=.o) 

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(MINILIBX) $(OBJS) d
	
	@$(CC) $(OFLAGS) $(FLAGS) $(OBJS) -o $(NAME) libs/minilibx/libmlx.a libs/ft_printf/libftprintf.a libs/get_next_line/gnl.a
	

$(MINILIBX):
	@echo "\n\033[0;35m⏳ LOADING...\033[0m\n"
	@make -s -C libs/minilibx
d: 
	@make -s -C libs/ft_printf
	@make -s -C libs/ft_printf/libft
	@make -s -C libs/get_next_line
	
	@echo "✅"

re: fclean all

clean:
	@rm -rf $(OBJS)
	@rm -f main/*.o
	@rm -f libs/minilibx/*.o
	@rm -f libs/ft_printf/libft/*.o
	@rm -f libs/ft_printf/*.o
	@rm -f libs/get_next_line/*.o
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libs/minilibx/*.a
	@rm -rf libs/ft_printf/libft/*.a
	@rm -rf libs/ft_printf/*.a
	@rm -rf libs/get_next_line/*.a
	@rm -rf so_long
	@echo "🗑️"

.PHONY: clean run fclean re all d 