/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:25:41 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/11 00:29:58 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movement(int key, t_game *game)
{
	movement_rotate(key, game);
	movement_move_ws(key, game);
	movement_move_ad(key, game);
}

int	on_input(int key, void *param)
{
	t_game		*game;
	t_vector	old_pos;

	game = (t_game *)param;
	old_pos.x = game->map->p_pos->x;
	old_pos.y = game->map->p_pos->y;
	if (key == KEY_ESC)
		ft_close_game(game, 4, "");
	movement(key, game);
	if (update_player_pos(game))
	{
		game->map->p_pos->x = old_pos.x;
		game->map->p_pos->y = old_pos.y;
	}
}

/**
 * Get the mouse movement and translate it on angle degree for camera rotation
 *
 * @details the function convert the mouse X position, ->
 * in range (0 - window width),
 * to the corrisponding value in range (0 to 360)
 *
 * @param x: x coord of the mouse (0 to window width)
 * @param y: y coord of the mouse
 * @param param: the pointer of the param passed to the function
*/
int	on_mouse_move(int x, int y, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (x > game->mouse_x_pos)
		game->map->degree += (float)(x - game->mouse_x_pos) * 4;
	else if (x < game->mouse_x_pos)
		game->map->degree -= (float)(game->mouse_x_pos - x) * 4;
	if (x > WIN_WIDTH / 1.2)
	{
		game->mouse_x_pos = WIN_WIDTH / 2;
		x = WIN_WIDTH / 2;
		mlx_mouse_move(game->mlx, game->window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	else if (x < WIN_WIDTH - (WIN_WIDTH / 1.2))
	{
		game->mouse_x_pos = WIN_WIDTH / 2;
		x = WIN_WIDTH / 2;
		mlx_mouse_move(game->mlx, game->window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	game->mouse_x_pos = x;
	update_player_pos(game);
}
