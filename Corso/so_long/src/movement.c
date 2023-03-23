/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:44:21 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/23 13:16:12 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_set_movement(t_game *game, t_vector old_player_pos)
{
	if ((game->player_pos.x != old_player_pos.x)
		|| (game->player_pos.y != old_player_pos.y))
		game->move_count++;
	ft_set_text(game);
}

void	ft_set_text(t_game *game)
{
	char	*text;

	text = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->window, 10, 12, 0xffffff, "Moves: ");
	mlx_string_put(game->mlx, game->window, 58, 12, 0xffffff, text);
	free(text);
}
