/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:43:16 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/23 13:16:15 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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
	int	time;

	time = ft_gettimestamp(game);
	if (time >= 140)
	{
		if (game->index == 3)
			game->index = 0;
		else
			game->index++;
		ft_print_map(game);
		ft_set_text(game);
		ft_enemy_moves(game);
	}
	ft_is_enemy(game);
	return (0);
}
