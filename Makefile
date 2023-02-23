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
	
	@$(CC) $(OFLAGS) $(FLAGS) $(OBJS) -o $(NAME) libs/minilibx/libmlx.a libs/ft_lib/libft.a -g
	

$(MINILIBX):
	@echo "\n\033[0;35m⏳ LOADING...\033[0m\n"
	@make -s -C libs/minilibx
d: 
	@make -s -C libs/ft_lib
	
	@echo "✅"

re: fclean all

clean:
	@rm -rf $(OBJS)
	@rm -f libs/minilibx/*.o
	@rm -f libs/ft_lib/*.o
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libs/minilibx/*.a
	@rm -rf libs/ft_lib/*.a
	@echo "🗑️"

.PHONY: clean run fclean re all d 