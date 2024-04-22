NAME	=	fractol
FILES	=	main.c
OBJ		=	$(FILES:.c=.o)
CC		=	cc
#CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	libft/libft.a
MLX		= 	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re