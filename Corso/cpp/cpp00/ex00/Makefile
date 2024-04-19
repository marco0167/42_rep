SRCS = ./megaphone.cpp\

OBJSDIR = objects

OBJS = $(addprefix $(OBJSDIR)/, ${SRCS:.c=.o})

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

NAME = megaphone

INCLUDE = -I include

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${INCLUDE} -g ${OBJS} -o ${NAME}

all: ${NAME}

clean:
		${RM} $(OBJSDIR)

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
		${RM} ${NAME}

re: fclean all
