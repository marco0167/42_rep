NAME = philo

SRCS = philo.c 

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
