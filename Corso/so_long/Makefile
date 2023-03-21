# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 19:22:19 by mcoppola          #+#    #+#              #
#    Updated: 2023/03/21 12:59:36 by mcoppola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c ./functions/classic_f.c ./functions/map_utils.c ./functions/set_map.c ./functions/close.c ./functions/print_map.c ./functions/hooks.c ./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CLFAGS = -Wall -Wextra -Werror

LINKAR =  -framework OpenGL -framework AppKit

RM = rm -f

NAME = so_long

PRINTF = printf/libftprintf.a

GET_NEXT_LINE = get_next_line/get_next_line.a

LIBX = minilibx_opengl_20191021/libmlx.a

INCLUDE = -I include

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${LINKAR} ${INCLUDE} ${OBJS} ${PRINTF} ${LIBX} -o ${NAME} -g

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all
