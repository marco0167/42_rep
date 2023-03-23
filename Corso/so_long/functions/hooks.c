/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:16:37 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/23 12:17:09 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_is_collectable(t_game *game)
{
	if (game->map.map[game->player_pos.y][game->player_pos.x] == 'C')
		game->objects.collectable--;
}
void	ft_is_exit(t_game *game, t_vector old_player_pos)
{
	if (game->map.map[game->player_pos.y][game->player_pos.x] == 'E')
	{
		if (game->objects.collectable == 0)
			ft_close_game(game, 3, "You win!");
		else
			game->player_pos = old_player_pos;
	}
}
void	ft_is_enemy(t_game *game)
{
	if (game->enemy_pos.x == game->player_pos.x
		&& game->enemy_pos.y == game->player_pos.y)
		ft_close_game(game, 3, "You lose!");
}

int	ft_input(int key, void *param)
{
	t_game		*game;
	t_vector	old_player_pos;

	game = (t_game *)param;
	old_player_pos = game->player_pos;
	mlx_clear_window(game->mlx, game->window);
	if (key == 53)
		ft_close_game(game, 4, "EXIT");
	 if (key == 13 && (game->map.map[game->player_pos.y - 1][game->player_pos.x] != '1'))
		game->player_pos.y -= 1;
	else if (key == 1 && (game->map.map[game->player_pos.y + 1][game->player_pos.x] != '1'))
		game->player_pos.y += 1;
	else if (key == 0 && (game->map.map[game->player_pos.y][game->player_pos.x - 1] != '1'))
		game->player_pos.x -= 1;
	else if (key == 2 && (game->map.map[game->player_pos.y][game->player_pos.x + 1] != '1'))
		game->player_pos.x += 1;
	ft_is_collectable(game);
	ft_is_exit(game, old_player_pos);
	ft_is_enemy(game);
	game->map.map[old_player_pos.y][old_player_pos.x] = '0';
	game->map.map[game->player_pos.y][game->player_pos.x] = 'P';
	ft_print_map(game);
	ft_set_movement(game, old_player_pos);
	return (0);
}

