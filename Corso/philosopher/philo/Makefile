NAME = philo

SRCS = ./sources/main.c ./sources/input_check.c ./sources/ft_atoi.c \
		./sources/ft_initializer.c ./sources/ft_starters.c \
		./sources/ft_close.c ./sources/ft_utils.c

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
