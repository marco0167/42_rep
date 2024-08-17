NAME = easyfind

CC = c++
CFLAGS = -Wall -Wextra -Werror -g
STDFLAG = -std=c++98

PARAMETER ?= ""

SRC = ./src/main.cpp


OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(STDFLAG) $(OBJ) -o $(NAME)
		@echo "$(NAME) ready (ง'̀-'́)ง"

clean:
		@rm -f $(OBJ)
		@if [ -f valgrind-out.txt ]; then rm valgrind-out.txt; fi
		@echo "CLEANED ┌П┐(ಠ_ಠ)"

fclean: clean
		@rm -f $(NAME)

leaks: re
	@valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
		./$(NAME) $(PARAMETER)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
