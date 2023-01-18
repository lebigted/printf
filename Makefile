# SRCS	=	forma_my_char.c \
# 			forma_my_nbr.c \
# 			forma_my_putstr.c \
# 			forma_my_nbrbase_seize.c \

# OBJS	= ${SRCS:.c=.o}

# NAME	= libftprintf.a

# CC		= gcc

# RM		= rm -f

# CFLAGS	= -Wall -Wextra -Werror

# .c.o:
# 		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# $(NAME):	${OBJS}
# 			ar rc ${NAME} ${OBJS}
# 			ranlib ${NAME}

# all:	${NAME}

# clean:
# 		${RM} ${OBJS}

# fclean:	clean
# 		${RM} ${NAME}

# re :	fclean all

# .PHONY: all clean fclean re

SRCS =	ft_printf.c\
		forma_my_char.c \
		forma_my_nbr.c \
		forma_my_putstr.c \
		ft_argputnbr_base.c \

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
