CC	= gcc -g
MINILIBX	= libs/minilibx/libmlx.a
NAME 		= so_long	
FLAGS		= -Wall -Wextra -Werror
OFLAGS		= -framework OpenGL -framework AppKit
SRCS 		= $(shell find main -name "*.c")
OBJS 		= $(SRCS:.c=.o) 

all : $(NAME)

$(NAME) : $(MINILIBX) $(OBJS) d
	@$(CC) $(OFLAGS) $(FLAGS) $(OBJS) -o $(NAME) libs/minilibx/libmlx.a libs/libft/libft.a

$(MINILIBX):
	@make -C libs/minilibx
d: 
	@make -C libs/libft
	@echo "✅"

re: fclean all

clean:
	@rm -rf $(OBJS)
	@rm -f libs/minilibx/*.o
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libs/minilibx/*.a
	@echo "🗑️"

.PHONY: clean run fclean re all d 