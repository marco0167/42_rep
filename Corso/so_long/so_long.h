/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:32:58 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/15 11:18:33 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>
# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"

// typedef struct s_pos
// {
// 	int	x;
// 	int	y;
// }				t_pos;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_collectable
{
	int	qnt;
	int	collected;
}				t_collectable;

typedef struct s_image
{
	void	*reference;
	char	*addr;
	int		endian;
}				t_image;

typedef struct s_player
{
	t_vector	position;
	t_image		*img;
}				t_player;

typedef struct s_exit
{
	t_vector	position;
	short int	visible;
}				t_exit;

typedef struct s_map
{
	char	*name;
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct s_game {
	void			*mlx;
	void		*window;
	t_map			map;
	t_player		player;
	t_exit			exit;
	t_collectable	collectable;
}				t_game;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int		ft_strlen2(char *s);
char	*map_checker(t_game *game, int argc, char **argv);
char	*dimension_checker(t_game *game);
char	*wall_cheker(t_game *game);
char	*obj_checker(t_game *game);
char	*obj_checker_return(t_game *game, int *p, int e);
char	*map_checker(t_game *game, int argc, char **argv);
void	set_map_matrix(t_game *game);

# endif
