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
typedef struct s_exit
{
	void	*door;
	void	*door_struct;
}				t_exit;


typedef struct s_sprites
{
	void	*floor;
	void	*wall[2];
	void	*exit[2];
	void	*collectable;
	void	*player;
}				t_sprites;

typedef struct s_objects
{
	int	player;
	int	collectable;
	int	exit;
}				t_objects;

typedef struct s_map
{
	char	*name;
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct s_game {
	void		*mlx;
	void		*window;
	t_map		map;
	t_sprites	*sprites;
	t_objects	objects;
	t_vector	player_pos;
	t_vector	exit_pos;
	int			bit;
	int			collectable_get;
	// short int	time_count;
}				t_game;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int		ft_strlen2(char *s);
int		map_checker(t_game *game, int argc, char **argv);
char	*dimension_checker(t_game *game);
char	*wall_cheker(t_game *game);
char	*obj_checker(t_game *game);
char	*obj_checker_return(t_game *game, int *p, int e);
void	set_map_matrix(t_game *game);
void	print_map(t_game *game);
void	sprite_assign(t_game *game);
int		input(int key, void *param);
void	close_game(t_game *game, int code, char *str);

# endif
