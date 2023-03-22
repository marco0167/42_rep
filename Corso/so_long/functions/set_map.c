/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:28:51 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/22 17:53:48 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_cheker(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		if (i == 0 || i == (game->map.height - 1))
		{
			while (game->map.map[i][j])
			{
				if (game->map.map[i][j] != '1')
					close_game(game, 2, "Mappa non circondata da muri");
				j++;
			}
		}
		else if (game->map.map[i][0] != '1' || game->map.map[i][game->map.width - 1] != '1')
			close_game(game, 2, "Mappa non circondata di muri");
		i++;
	}
}

void	obj_checker_return(t_game *game)
{
	if (game->objects.player != 1)
		close_game(game, 2, "Player missing");
	if (game->objects.exit < 1)
		close_game(game, 2, "Exit missing");
	if (game->objects.collectable < 1)
		close_game(game, 2, "Collectable missing");
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

void	obj_checker(t_game *game)
{
	int i;
	int j;

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
	obj_checker_return(game);
}

int	map_checker(t_game *game, int argc, char **argv)
{
	int nameLen;
	int i;

	if (argc != 2)
	{
		close_game(game, 1, "Wrong number of arguments");
		return (1);
	}
	else
	{
		i = 3;
		nameLen = ft_strlen(argv[1]) - 1;
		while (i >= 0)
		{
			if (argv[1][nameLen] != ".ber"[i])
			{
				close_game(game, 1, "Map not .ber");
				return (1);
			}
			i--;
			nameLen--;
		}
		game->map.name = ft_strdup(argv[1]);
	}
	return (0);
}

void set_map_matrix(t_game *game)
{
	int i;
	int fd;
	char *line;

	game->map.height = 0;
	fd = open(game->map.name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		game->map.height++;
	}
	free(line);
	close(fd);
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
	// i = 0;
	// while (game->map.map[i] != 0)
	// {
	// 	ft_printf("string = %s\n", game->map.map[i]);
	// 	i++;
	// }
	dimension_checker(game);
	wall_cheker(game);
	obj_checker(game);
}
