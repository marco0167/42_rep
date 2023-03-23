/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:29:11 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/23 15:32:13 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_dimension_checker(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		if (game->map.width != ft_strlen(game->map.map[i]))
			ft_close_game(game, 2, "map not rectangle");
		i++;
	}
}

void	ft_set_map_matrix_first_part(t_game *game, char *line, int fd)
{
	game->map.height = 0;
	fd = open(game->map.name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
    {
		free(line);
		ft_close_game(game, 1, "Empty or non existing map");
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		game->map.height++;
	}
	free(line);
	close(fd);
}

void	ft_obj_checker_return(t_game *game)
{
	if (game->objects.player != 1)
		ft_close_game(game, 2, "Player missing");
	if (game->objects.exit < 1)
		ft_close_game(game, 2, "Exit missing");
	if (game->objects.collectable < 1)
		ft_close_game(game, 2, "Collectable missing");
}

void	ft_char_checker(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.height - 1)
	{
		j = 1;
		while (j < game->map.width - 1)
		{
			if (game->map.map[i][j] != '1' && game->map.map[i][j] != '0'
				&& game->map.map[i][j] != 'P' && game->map.map[i][j] != 'E'
				&& game->map.map[i][j] != 'X' && game->map.map[i][j] != 'C')
				ft_close_game(game, 2, "Map contains invalid characters");
			j++;
		}
		i++;
	}
}
