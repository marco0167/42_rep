NAME = philo

SRCS = ./sources/main.c ./sources/input_check.c ./sources/ft_atoi.c \
		./sources/close.c ./sources/init.c ./sources/routines.c \
		./sources/starters.c ./sources/utils.c


OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror -pthread

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean : clean
	${RM} ${NAME}

re: fclean all
