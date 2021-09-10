

NAME = libftprintf.a
SRC = libft_func.c printf_parser.c ft_printf_main.c  ft_printf_u_x.c ft_printf_int.c   ft_printf.c  ft_atoi.c ft_itoa.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re 

%.o: %.c ft_printf.h
	gcc $(CFLAGS) -c $<
all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ) 
fclean: clean
	rm -f $(NAME)
re: fclean all
