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
# include <sys/time.h>

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
	void	*wall[5];
	void	*exit[2];
	void	*collectable;
	void	*player;
	void	*enemy[4];
}				t_sprites;

typedef struct s_objects
{
	int	player;
	int	enemy;
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
	void			*mlx;
	void			*window;
	t_map			map;
	t_sprites		*sprites;
	t_objects		objects;
	t_vector		player_pos;
	t_vector		enemy_pos;
	t_vector		exit_pos;
	int				bit;
	int				collectable_get;
	int				move_count;
	short int		index;
	short int		enemy_dir;
	struct timeval	curr_tm;
}				t_game;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int		ft_strlen2(char *s);
int		ft_map_checker(t_game *game, int argc, char **argv);
void	ft_dimension_checker(t_game *game);
void	ft_wall_cheker(t_game *game);
void	ft_obj_checker(t_game *game);
void	ft_obj_checker_return(t_game *game);
void	ft_set_map_matrix(t_game *game);
void	ft_print_map(t_game *game);
void	ft_sprite_assign(t_game *game);
int		ft_input(int key, void *param);
void	ft_close_game(t_game *game, int code, char *str);
void	ft_set_movement(t_game *game, t_vector old_player_pos);
char	*ft_itoa(int n);
int		ft_next_frame(t_game *game);
void	ft_set_text(t_game *game);
void	ft_enemy_moves(t_game *game);

# endif
