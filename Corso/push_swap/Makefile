SRCS = ./src/main.c ./src/list.c ./src/moves/push.c \
		./src/moves/reverse_rotate.c ./src/moves/rotate.c ./src/moves/swap.c \
		./src/utils/ft_atoi.c ./src/utils/ft_end.c ./src/utils/ft_split.c \
		./src/check/ft_check_numbers.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME} -g

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
