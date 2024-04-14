/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:59 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:27:00 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/**
 * Check if one of angle penetrate the wall
 *
 * @param game: the game struct
 * @param x: the x coord of the origin of the player
 * @param x: the y coord of the origin of the player
 * @return 1 if penetrate a wall 0 otherwise
*/
int	is_penetrating_wall(t_game *game, int x, int y)
{
	if (game->map->map_matrix
		[(y - MAP_BIT / 4) / MAP_BIT]
		[(x - MAP_BIT / 4) / MAP_BIT] == '1'
		|| game->map->map_matrix
		[(y - MAP_BIT / 4) / MAP_BIT]
		[(x + MAP_BIT / 4) / MAP_BIT] == '1'
		|| game->map->map_matrix
		[(y + MAP_BIT / 4) / MAP_BIT]
		[(x - MAP_BIT / 4) / MAP_BIT] == '1'
		|| game->map->map_matrix
		[(y + MAP_BIT / 4) / MAP_BIT]
		[(x + MAP_BIT / 4) / MAP_BIT] == '1'
	)
		return (1);
	return (0);
}

/**
 * Update the player position on the map.
 *
 * @details if the player new position not let it penetrate the wall
 * reprint the map, ray cone and the player
 *
 * @param game: the game struct
*/
int	update_player_pos(t_game *game)
{
	if (is_penetrating_wall(game, game->map->p_pos->x, game->map->p_pos->y))
	{
		game->movespeed = 1;
		return (1);
	}
	else
		game->movespeed = MOVESPEED;
	draw_straight_line_from_player(game, game->map->degree);
	return (0);
}
