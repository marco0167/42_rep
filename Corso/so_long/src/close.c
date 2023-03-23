/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:16:47 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/23 13:15:56 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_close_game(t_game *game, int code, char *str)
{
	int	i;

	if (code > 2)
	{
		mlx_destroy_image(game->mlx, game->sprites->collectable);
		mlx_destroy_image(game->mlx, game->sprites->floor);
		mlx_destroy_image(game->mlx, game->sprites->player);
		free(game->sprites);
		mlx_destroy_window(game->mlx, game->window);
	}
	if (code > 1)
	{
		i = 0;
		while (game->map.map[i])
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.name);
		free(game->map.map);
	}
	if (code > 0)
		free(game);
	ft_printf("%s\n", str);
	exit(0);
}
