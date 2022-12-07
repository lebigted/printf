SRCS = forma_my_putstr.c forma_my_nbr.c forma_my_char.c ft_printf.c other_fonction.c convert_fonction.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
all : $(NAME)

.c.o:
		gcc -Wall -Wextra -Werror -c -I ./includes $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
