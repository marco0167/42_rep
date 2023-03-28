SRC = ft_printf.c ft_dec_to_string.c ft_hex_to_string.c \
		ft_print_string.c ft_printf_condition.c ft_revert_string.c \
		ft_to_upper.c

OBJ = ${SRC:.c=.o}
NAME = libftprintf.a
LIBC = ar -r
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

${NAME}: ${OBJ}
	@${LIBC} ${NAME} ${OBJ}

all: ${NAME}

clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all
