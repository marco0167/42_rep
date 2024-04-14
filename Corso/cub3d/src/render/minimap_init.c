/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:55 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:26:56 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_pos(t_game *game, int x, int y, int deg)
{
	game->map->degree = deg;
	game->map->p_pos->x = x * MAP_BIT + (MAP_BIT / 2);
	game->map->p_pos->y = y * MAP_BIT + (MAP_BIT / 2);
}

void	init_tile_color_selector(t_game *game, int y, int x)
{
	if (game->map->map_matrix[y][x] == 'N')
		set_pos(game, x, y, 270);
	else if (game->map->map_matrix[y][x] == 'S')
		set_pos(game, x, y, 90);
	else if (game->map->map_matrix[y][x] == 'E')
		set_pos(game, x, y, 0);
	else if (game->map->map_matrix[y][x] == 'W')
		set_pos(game, x, y, 180);
}

void	minimap_init(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map_matrix[y])
	{
		x = 0;
		while (game->map->map_matrix[y][x])
		{
			init_tile_color_selector(game, y, x);
			x++;
		}
		y++;
	}
}
