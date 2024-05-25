NAME = diamondgrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -Wshadow -Wno-shadow
STDFLAG = -std=c++98

SRC = ./src/main.cpp \
		./class/ClapTrap.cpp \
		./class/ScavTrap.cpp \
		./class/FragTrap.cpp \
		./class/DiamondTrap.cpp \


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
