NAME	=	fractol
FILES	=	main.c
OBJ		=	$(FILES:.c=.o)
CC		=	cc
#CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	libft/libft.a
MLX		= 	mlx_linux/libmlx.a -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C mlx_linux
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	make -C libft clean
	make -C mlx_linux clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re