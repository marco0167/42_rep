/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:43:16 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/22 15:57:46 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	ft_gettimestamp(t_game *game)
{
	struct timeval	now;
	int				res;

	gettimeofday(&now, NULL);
	res = (((now.tv_sec * 1000) + (now.tv_usec / 1000))
			- ((game->curr_tm.tv_sec * 1000) + (game->curr_tm.tv_usec / 1000)));
	if (res >= 140)
		game->curr_tm = now;
	return (res);
}

int	ft_next_frame(t_game *game)
{
	if (ft_gettimestamp(game) >= 140)
	{
		if (game->index == 4)
			game->index = 0;
		else
			game->index++;
		ft_charge_map_on_screen(game);
	}
	if ((game->objects.enemy > 0) && game->enemy_pos.x == game->player_pos.x
		&& game->enemy_pos.y == game->player_pos.y)
	{
		ft_printf("You Lose !!\n");
		ft_close(game);
	}
	return (0);
}
