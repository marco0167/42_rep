NAME = span

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

PARAMETER ?= ""

SRC = ./src/main.cpp \
		./class/Span.cpp


OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
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
