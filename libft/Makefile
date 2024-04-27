NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
FILES	= ft_strcmp.c ft_isdigit.c ft_atoi.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_strlen.c ft_putchar_fd.c
OBJ		= $(FILES:.c=.o)
CC		= cc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all