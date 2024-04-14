SRCS = ./src/main.c \
		./src/get_next_line/get_next_line_utils.c \
		./src/get_next_line/get_next_line.c \
		./src/libft/ft_strstr.c \
		./src/libft/ft_strdup.c \
		./src/libft/ft_memcpy.c \
		./src/libft/ft_split.c \
		./src/libft/ft_atoi.c \
		./src/libft/ft_strtrim.c \
		./src/libft/ft_substr.c \
		./src/free/free.c \
		./src/end_game/end_game.c \
		./src/map/set_map.c \
		./src/map/set_map_utils.c \
		./src/map/set_map_utils2.c \
		./src/map/set_map_utils3.c \
		./src/map/set_map_utils4.c \
		./src/map/checker.c \
		./src/map/utils.c \
		./src/render/minimap_init.c \
		./src/render/minimap_update.c \
		./src/render/utils_01.c \
		./src/render/playerfov.c \
		./src/render/line_length_calculator_helper.c \
		./src/render/print_line_wall_helper.c \
		./src/render/textures_utils.c \
		./src/utils/utils_01.c \
		./src/input/input.c \
		./src/input/input_utils.c \

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/, ${SRCS:.c=.o})

CC = gcc

CLFAGS = -I/usr/include -Imlx_linux -O3 -Wall -Wextra -Werror

LINKAR = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

RM = rm -rf

NAME = cub3D

INCLUDE = -I include

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${INCLUDE} -g ${OBJS} ${LINKAR} -o ${NAME}

all: ${NAME}

clean:
	${RM} $(OBJSDIR)

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	${RM} ${NAME}

re: fclean all
