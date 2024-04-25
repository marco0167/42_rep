NAME = tests

CC = c++
CFLAGS = -Wall -Wextra -Werror -g
STDFLAG = -std=c++98

SRC = ./tests.cpp ./Account.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(STDFLAG) $(OBJ) -o $(NAME)
		@echo "\n$(NAME) ready (ง'̀-'́)ง\n"

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)
		@echo "\nCLEANED ┌П┐(ಠ_ಠ)\n"

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
