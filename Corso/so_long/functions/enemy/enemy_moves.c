/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:28:07 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/23 12:10:48 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


void	ft_enemy_move_lef(t_game *game)
{
	if (game->map.map[game->enemy_pos.y][game->enemy_pos.x - 1] == '0' || game->map.map[game->enemy_pos.y][game->enemy_pos.x - 1] == 'P')
	{
		game->map.map[game->enemy_pos.y][game->enemy_pos.x] = '0';
		game->enemy_pos.x--;
		ft_is_enemy(game);
		game->map.map[game->enemy_pos.y][game->enemy_pos.x] = 'X';
		ft_print_map(game);
	}
	else
	{

		game->enemy_dir = 1;
	}
}

void	ft_enemy_move_right(t_game *game)
{
	if (game->map.map[game->enemy_pos.y][game->enemy_pos.x + 1] == '0' || game->map.map[game->enemy_pos.y][game->enemy_pos.x + 1] == 'P')
	{
		game->map.map[game->enemy_pos.y][game->enemy_pos.x] = '0';
		game->enemy_pos.x++;
		ft_is_enemy(game);
		game->map.map[game->enemy_pos.y][game->enemy_pos.x] = 'X';
		ft_print_map(game);
	}
	else
	{
		ft_is_enemy(game);
		game->enemy_dir = 0;
	}
}

void	ft_enemy_moves(t_game *game)
{
	if (game->enemy_dir == 0)
		ft_enemy_move_lef(game);
	else if (game->enemy_dir == 1)
		ft_enemy_move_right(game);
	ft_set_text(game);
}
