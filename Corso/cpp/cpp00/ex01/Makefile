NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -g
STDFLAG = -std=c++98

SRC = phonebook.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(STDFLAG) $(OBJ) -o $(NAME)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

all: $(NAME)
	@echo "\n$(NAME) ready (ง'̀-'́)ง\n"

.PHONY: all clean fclean re
