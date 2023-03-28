NAME_S = server
NAME_C = client

SRC_S = server.c
SRC_C = client.c ./src/ft_atoi.c

OBJ_S = $(SRC_S.o=.c)
OBJ_C = $(SRC_C.o=.c)

FT_PRINTF := ft_printf

FLAGS = -Wall -Werror -Wextra
CC = gcc

all:
	make -C $(FT_PRINTF)
	$(CC) $(FLAGS) $(SRC_S) ft_printf/libftprintf.a -o $(NAME_S)
	$(CC) $(FLAGS) $(SRC_C) ft_printf/libftprintf.a -o $(NAME_C)

server:
	make -C $(FT_PRINTF)
	$(CC) $(FLAGS) $(SRC_S) ft_printf/libftprintf.a -o $(NAME_S)

client:
	make -C $(FT_PRINTF)
	$(CC) $(FLAGS) $(SRC_C) ft_printf/libftprintf.a -o $(NAME_C)

clean:
	make clean -C $(FT_PRINTF)
	rm -f $(OBJ_S)
	rm -f $(OBJ_C)

fclean:	clean
	make fclean -C $(FT_PRINTF)
	rm -f $(NAME_S)
	rm -f $(NAME_C)

re:	fclean all clean

.PHONY: clean fclean re all
