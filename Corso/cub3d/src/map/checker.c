/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:22 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:55:35 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	char_verify(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->map->map_matrix;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!is_space(map[y][x]) && map[y][x] != '1'
				&& !is_content(map[y][x]))
				ft_close_game(game, 3, "Error\nFound illegal charcacter "\
				"inside the map!");
			x++;
		}
		y++;
	}
}

void	close_verify(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->map->map_matrix;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_content(map[y][x]) && (x == 0 || y == 0
				|| x == game->map->width - 1 || y == game->map->height - 1))
				ft_close_game(game, 3, "Error\nMap not close1!");
			if (is_content(map[y][x]) && (is_space(map[y][x - 1])
				|| is_space(map[y][x + 1]) || is_space(map[y - 1][x])
				|| is_space(map[y + 1][x]) || is_space(map[y - 1][x - 1])
				|| is_space(map[y - 1][x + 1]) || is_space(map[y + 1][x - 1])
				|| is_space(map[y + 1][x + 1]))
			)
				ft_close_game(game, 3, "Error\nMap not close2!");
			x++;
		}
		y++;
	}
}

void	check_player(t_game *game)
{
	int		x;
	int		y;
	char	**map;
	int		player;

	y = 0;
	map = game->map->map_matrix;
	player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
			{
				if (player)
					ft_close_game(game, 3, "Error\nMultiple player found!");
				player = 1;
			}
			x++;
		}
		y++;
	}
	if (!player)
		ft_close_game(game, 3, "Error\nNo player found!");
}

void	check_file_exists(t_game *game)
{
	if (open(game->map->path_n, O_RDONLY) < 0
		|| open(game->map->path_s, O_RDONLY) < 0
		|| open(game->map->path_e, O_RDONLY) < 0
		|| open(game->map->path_w, O_RDONLY) < 0)
		ft_close_game(game, 3, ERROR_TEXTURES);
}

void	full_check(t_game *game)
{
	char_verify(game);
	close_verify(game);
	check_player(game);
	check_file_exists(game);
}
