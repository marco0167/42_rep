NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -g
STDFLAG = -std=c++98

SRC = megaphone.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "\n$(NAME) ready (ง'̀-'́)ง\n"

std: $(OBJ)
		$(CC) $(CFLAGS) $(STDFLAG) $(OBJ) -o $(NAME)

test: $(NAME)
		./$(NAME) "shhhhh... I think the students are asleep..."
		./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
		./$(NAME) "This is a test"
		./$(NAME)
clean:
		@rm -f $(OBJ)
		@echo "\nCLEANED ┌П┐(ಠ_ಠ)\n"

fclean: clean
		@rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
