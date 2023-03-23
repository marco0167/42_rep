/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:28:51 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/23 13:03:41 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_wall_cheker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		if (i == 0 || i == (game->map.height - 1))
		{
			while (game->map.map[i][j])
			{
				if (game->map.map[i][j] != '1')
					ft_close_game(game, 2, "Mappa non circondata da muri");
				j++;
			}
		}
		else if (game->map.map[i][0] != '1'
				|| game->map.map[i][game->map.width - 1] != '1')
			ft_close_game(game, 2, "Mappa non circondata di muri");
		i++;
	}
}

void	ft_get_pos(t_game *game, int *i, int *j)
{
	if (game->map.map[(*i)][(*j)] == 'P')
	{
		game->objects.player++;
		game->player_pos.x = (*j);
		game->player_pos.y = (*i);
	}
	else if (game->map.map[(*i)][(*j)] == 'E')
	{
		game->objects.exit++;
		game->exit_pos.x = (*j);
		game->exit_pos.y = (*i);
	}
	else if (game->map.map[(*i)][(*j)] == 'X')
	{
		game->objects.enemy++;
		game->enemy_pos.x = (*j);
		game->enemy_pos.y = (*i);
	}
	else if (game->map.map[(*i)][(*j)] == 'C')
		game->objects.collectable++;
}

void	ft_obj_checker(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.height - 1)
	{
		j = 1;
		while (j < game->map.width - 1)
		{
			ft_get_pos(game, &i, &j);
			j++;
		}
		i++;
	}
	ft_obj_checker_return(game);
}

void	ft_map_checker(t_game *game, int argc, char **argv)
{
	int	name_len;
	int	i;

	if (argc != 2)
		ft_close_game(game, 1, "Wrong number of arguments");
	else
	{
		i = 3;
		name_len = ft_strlen(argv[1]) - 1;
		while (i >= 0)
		{
			if (argv[1][name_len] != ".ber"[i])
				ft_close_game(game, 1, "Map not .ber");
			i--;
			name_len--;
		}
		game->map.name = ft_strdup(argv[1]);
	}
}

void	ft_set_map_matrix(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	ft_set_map_matrix_first_part(game, line, fd);
	i = 0;
	fd = open(game->map.name, O_RDONLY);
	game->map.map = malloc(sizeof(char *) * game->map.height + 1);
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		game->map.map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map.map[i] = 0;
	game->map.width = ft_strlen(game->map.map[0]);
	ft_dimension_checker(game);
	ft_wall_cheker(game);
	ft_obj_checker(game);
}
