/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:42 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:26:43 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	add_to_matrix(t_game *game, char *line, int i)
{
	int		c;
	char	*space;
	int		l_len;

	if (ft_strlen(line) && !ft_strstr(line, "NO ")
		&& !ft_strstr(line, "SO ") && !ft_strstr(line, "WE ")
		&& !ft_strstr(line, "EA ") && !ft_strstr(line, "F ")
		&& !ft_strstr(line, "C "))
	{
		l_len = ft_strlen(line);
		if (l_len < game->map->width)
		{
			space = malloc(sizeof(char) * (game->map->width - l_len) + 1);
			c = 0;
			while (c < (game->map->width - l_len))
				space[c++] = ' ';
			space[c] = '\0';
			line = ft_strjoin(line, space);
			free(space);
		}
		game->map->map_matrix[i++] = ft_strdup(line);
	}
	free(line);
	return (i);
}

/**
 * Set the map inside the map matrix and add extra spaces if the
 * line is too short
 *
 * @param game: game struct
*/
void	set_map_in_matrix(t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	game->map->map_matrix = malloc(sizeof(char *) * game->map->height);
	fd = open(game->map->name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		i = add_to_matrix(game, line, i);
		line = get_next_line(fd);
	}
	game->map->map_matrix[i] = '\0';
	free(line);
	close(fd);
}

void	read_map_conditions(t_game *game, char *line)
{
	int		line_len;
	int		gm_h;
	int		i;

	gm_h = game->map->height == 0;
	if (check_condition_no(game, line, gm_h))
		(void)i;
	else if (check_condition_so(game, line, gm_h))
		(void)i;
	else if (check_condition_we(game, line, gm_h))
		(void)i;
	else if (check_condition_ea(game, line, gm_h))
		(void)i;
	else if (check_condition_f(game, line, gm_h))
		(void)i;
	else if (check_condition_c(game, line, gm_h))
		(void)i;
	else if (ft_strlen(line))
		read_map_condition_h(game, line, &line_len);
	else if (game->map->height > 0)
	{
		game->err = 1;
	}
}

/**
 * Read the map file and add get all the content inside the struct
 *
 * @param game: game struct
*/
void	read_map(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map->name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_close_game(game, 1, "Error\nEmpty or non existing map");
	}
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		read_map_conditions(game, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!game->map->height || game->err)
		ft_close_game(game, 2, "Error\nOn map file");
	game->map->height++;
	set_map_in_matrix(game);
}

/**
 * - Controlla se il numero di argomenti passati sia corretto
 * - Controlla se l'estensione della mappa sia '.cub'
 *
 * @param game: the game struct
 * @param argc: argc from main
 * @param argv: argv from main
*/
void	ft_map_checker(t_game *game, int argc, char **argv)
{
	int	n_len;

	if (argc != 2)
		ft_close_game(game, 0, "Error\nWrong number of argument!");
	n_len = ft_strlen(argv[1]);
	if (argv[1][n_len - 4] != '.' || argv[1][n_len - 3] != 'c'
			|| argv[1][n_len - 2] != 'u' || argv[1][n_len - 1] != 'b')
		ft_close_game(game, 0, "Error\nMap not .cub");
	game->map->name = ft_strdup(argv[1]);
	read_map(game);
	if (!game->map->color_f || !game->map->color_c || !game->map->path_n
		|| !game->map->path_s || !game->map->path_e || !game->map->path_w)
		ft_close_game(game, 3, ERROR_CONFIG);
	full_check(game);
}
