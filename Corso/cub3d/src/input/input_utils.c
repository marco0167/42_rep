/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:25:34 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:25:35 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movement_rotate(int key, t_game *game)
{
	if (key == KEY_RIGHT)
		game->map->degree += CAMERASPEED;
	if (key == KEY_LEFT)
		game->map->degree -= CAMERASPEED;
}

void	movement_move_ws(int key, t_game *game)
{
	if (key == KEY_W)
	{
		game->map->p_pos->y += game->movespeed
			* sin((game->map->degree * PI) / 180);
		game->map->p_pos->x += game->movespeed
			* cos((game->map->degree * PI) / 180);
	}
	if (key == KEY_S)
	{
		game->map->p_pos->y -= game->movespeed
			* sin((game->map->degree * PI) / 180);
		game->map->p_pos->x -= game->movespeed
			* cos((game->map->degree * PI) / 180);
	}
}

void	movement_move_ad(int key, t_game *game)
{
	if (key == KEY_A)
	{
		game->map->p_pos->y -= game->movespeed
			* cos((game->map->degree * PI) / 180);
		game->map->p_pos->x += game->movespeed
			* sin((game->map->degree * PI) / 180);
	}
	if (key == KEY_D)
	{
		game->map->p_pos->y += game->movespeed
			* cos((game->map->degree * PI) / 180);
		game->map->p_pos->x -= game->movespeed
			* sin((game->map->degree * PI) / 180);
	}
}
