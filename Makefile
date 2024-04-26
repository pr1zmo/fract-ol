NAME	=	fractol
FILES	=	src/fractol.c src/julia.c src/mandelbrot.c src/render.c src/color.c \
			src/math_utils.c src/configs.c src/mouse.c src/errors.c \
			src/burning_ship.c src/math_utils_2.c

OBJ		=	$(FILES:.c=.o)
CC		=	cc
#CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	libft/libft.a
MLX		=	mlx/libmlx.a -lXext -lX11 -lm

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