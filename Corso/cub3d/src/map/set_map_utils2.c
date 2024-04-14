/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:30 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:26:31 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_condition_f(t_game *game, char *line, int gm_h)
{
	game->tmp = ft_strstr(line, "F");
	if (game->map->color_f && ft_strlen(game->tmp)
		&& string_to_num_arr(game->tmp + 1, ',') == game->map->color_f)
		game->err = 1;
	if (game->tmp != 0 && gm_h && !game->map->color_f)
	{
		game->map->color_f = string_to_num_arr(game->tmp + 1, ',');
		return (1);
	}
	return (0);
}

int	check_condition_c(t_game *game, char *line, int gm_h)
{
	game->tmp = ft_strstr(line, "C");
	if (game->map->color_c && ft_strlen(game->tmp)
		&& string_to_num_arr(game->tmp + 1, ',') == game->map->color_c)
		game->err = 1;
	if (game->tmp != 0 && gm_h && !game->map->color_c)
	{
		game->map->color_c = string_to_num_arr(game->tmp + 1, ',');
		return (1);
	}
	return (0);
}

void	check_widht(t_game *game, int line_len)
{
	if (line_len > game->map->width)
		game->map->width = line_len;
}

void	read_map_condition_h(t_game *game, char *line, int *line_len)
{
	game->map->height++;
	*line_len = ft_strlen(line);
	check_widht(game, *line_len);
}
