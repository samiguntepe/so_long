# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 23:59:38 by sguntepe          #+#    #+#              #
#    Updated: 2023/03/08 15:03:59 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc -g
MINILIBX	= libs/minilibx/libmlx.a
NAME 		= so_long
BNAME		= so_long_bonus
FLAGS		= -Wall -Wextra -Werror 
OFLAGS		= -framework OpenGL -framework AppKit
SRCS 		= $(shell find main -name "*.c")
OBJS 		= $(SRCS:.c=.o)
BSRCS		= $(shell find bonus -name "*.c")
BOBJS		= $(BSRCS:.c=.o)

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(MINILIBX) $(OBJS) d
	
	@$(CC) $(OFLAGS) $(FLAGS) $(OBJS) -o $(NAME) libs/minilibx/libmlx.a libs/ft_printf/libftprintf.a libs/get_next_line/gnl.a

bonus: $(BNAME) 

$(BNAME) : $(MINILIBX) $(BOBJS) d

	@$(CC) $(OFLAGS) $(FLAGS) $(BOBJS) -o $(BNAME) libs/minilibx/libmlx.a libs/ft_printf/libftprintf.a libs/get_next_line/gnl.a

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
	@rm -rf $(BOBJS)
	@rm -f main/*.o
	@rm -f bonus/*.o
	@rm -f libs/minilibx/*.o
	@rm -f libs/ft_printf/libft/*.o
	@rm -f libs/ft_printf/*.o
	@rm -f libs/get_next_line/*.o
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BNAME)
	@rm -rf libs/minilibx/*.a
	@rm -rf libs/ft_printf/libft/*.a
	@rm -rf libs/ft_printf/*.a
	@rm -rf libs/get_next_line/*.a
	@echo "🗑️"

norm:
	@norminette bonus
	@norminette main

.PHONY: clean run fclean re all d bonus norm