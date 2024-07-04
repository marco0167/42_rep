NAME = bureaucrat

CC = c++
CFLAGS = -Wall -Wextra -Werror -g
STDFLAG = -std=c++98

SRC = ./src/main.cpp \
		./class/Bureaucrat.cpp \
		./class/Form.cpp \


OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(STDFLAG) $(OBJ) -o $(NAME)
		@echo "\n$(NAME) ready (ง'̀-'́)ง\n"

clean:
		@rm -f $(OBJ)
		@echo "\nCLEANED ┌П┐(ಠ_ಠ)\n"

fclean: clean
		@rm -f $(NAME)

leaks: re
	@valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
		./$(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
