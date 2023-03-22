/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:44:21 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/22 16:57:33 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_set_movement(t_game *game, t_vector old_player_pos)
{
	char	*text;

	text =  ft_itoa(game->move_count);
	if ((game->player_pos.x != old_player_pos.x) || (game->player_pos.y != old_player_pos.y))
	{
		game->move_count++;
	}
	mlx_string_put(game->mlx, game->window, 10, 12, 0xffffff, "Moves: ");
	mlx_string_put(game->mlx, game->window, 58, 12, 0xffffff, text);
	free(text);
}
