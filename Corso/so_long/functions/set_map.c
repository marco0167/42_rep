/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:28:51 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/18 15:05:40 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *wall_cheker(t_game *game)
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
				{
					return ("mappa non circondata di muri qui");
				}
				j++;
			}
		}
		else if (game->map.map[i][0] != '1' || game->map.map[i][game->map.width - 1] != '1')
			return ("mappa non circondata di muri");
		i++;
	}
	return (0);
}

char *obj_checker_return(t_game *game, int *p, int e)
{
	if ((*p) != 1)
		return ("Player error");
	if (e < 1)
		return ("Exit error");
	if (game->objects.collectable < 1)
		return ("Collectable error");
	return (0);
}

void	get_pos(t_game *game, int *i, int *j, int *p, int *e)
{
	if (game->map.map[(*i)][(*j)] == 'P')
	{
		(*p)++;
		game->player_pos.x = (*j);
		game->player_pos.y = (*i);
	}
	else if (game->map.map[(*i)][(*j)] == 'E')
	{
		(*e)++;
		ft_printf("EXIT pos: %d, %d", (*j), (*i));
		game->exit_pos.x = (*j);
		game->exit_pos.y = (*i);
	}
	else if (game->map.map[(*i)][(*j)] == 'C')
		game->objects.collectable++;
}

char *obj_checker(t_game *game)
{
	int i;
	int j;
	int p;
	int e;

	i = 1;
	p = 0;
	e = 0;
	game->objects.collectable = 0;
	while (i < game->map.height - 1)
	{
		j = 1;
		while (j < game->map.width - 1)
		{
			get_pos(game, &i, &j, &p, &e);
			j++;
		}
		i++;
	}
	obj_checker_return(game, &p, e);
	return (0);
}

char *map_checker(t_game *game, int argc, char **argv)
{
	int nameLen;
	int i;

	if (argc != 2)
		return ("Map error");
	else
	{
		i = 3;
		nameLen = ft_strlen(argv[1]) - 1;
		while (i >= 0)
		{
			if (argv[1][nameLen] != ".ber"[i])
				return ("Map not .ber");
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

	i = 0;
	while (game->map.map[i] != 0)
	{
		ft_printf("string = %s\n", game->map.map[i]);
		i++;
	}
	ft_printf("dimension %s\n", dimension_checker(game));
	ft_printf("wall %s\n", wall_cheker(game));
	ft_printf("obj %s\n", obj_checker(game));
}
