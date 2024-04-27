NAME = reference

CC = c++
CFLAGS = -Wall -Wextra -Werror -g
STDFLAG = -std=c++98

SRC = ./src/main.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(STDFLAG) $(OBJ) -o $(NAME)
		@echo "\n$(NAME) ready (ง'̀-'́)ง\n"

clean:
		@rm -f $(OBJ)
		@echo "\nCLEANED ┌П┐(ಠ_ಠ)\n"

fclean: clean
		@rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
