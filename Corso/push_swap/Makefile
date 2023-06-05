MAIN = ./src/main.c

SRCS = ./src/list.c ./src/moves/ft_push.c \
		./src/moves/ft_reverse_rotate.c ./src/moves/ft_rotate.c ./src/moves/ft_swap.c \
		./src/utils/ft_atoi.c ./src/utils/ft_end.c ./src/utils/ft_split.c \
		./src/check/ft_check_numbers.c ./src/moves/ft_moves.c ./src/sorting/ft_sorting_alg.c \
		./src/sorting/ft_set_cost.c ./src/sorting/ft_small_sorting.c ./src/sorting/ft_medium_sorting.c\
		./src/utils/ft_sorting_alg_util.c ./src/utils/ft_set_cost_util.c

BONUS = ./src_bonus/checker.c ./src_bonus/get_next_line.c ./src_bonus/get_next_line_utils.c


MOBJS = ${MAIN:.c=.o}
OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)

NAME = push_swap
BNAME = checker

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

# OUT = ${filter-out src/main.o , ${OBJS}}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS}  $(MAIN) -o ${NAME} -g

all: ${NAME}

bonus: ${BOBJS}
	${CC} ${FLAGS} ${BOBJS} $(OBJS) -o ${BNAME} -g

clean:
	${RM} ${OBJS}
	${RM} ${BOBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BNAME}

re: fclean all bonus
