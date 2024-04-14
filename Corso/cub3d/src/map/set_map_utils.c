/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:26 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:26:27 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_condition_no(t_game *game, char *line, int gm_h)
{
	game->tmp = ft_strstr(line, "NO");
	if (ft_strlen(game->map->path_n)
		&& ft_strlen(game->tmp) && ft_strstr(game->tmp, game->map->path_n))
		game->err = 1;
	if (game->tmp != 0 && gm_h && !ft_strlen(game->map->path_n))
	{
		game->map->path_n = ft_strtrim(game->tmp + 2, " \n");
		return (1);
	}
	return (0);
}

int	check_condition_so(t_game *game, char *line, int gm_h)
{
	game->tmp = ft_strstr(line, "SO");
	if (ft_strlen(game->map->path_s)
		&& ft_strlen(game->tmp) && ft_strstr(game->tmp, game->map->path_s))
		game->err = 1;
	if (game->tmp != 0 && gm_h && !game->map->path_s)
	{
		game->map->path_s = ft_strtrim(game->tmp + 2, " \n");
		return (1);
	}
	return (0);
}

int	check_condition_we(t_game *game, char *line, int gm_h)
{
	game->tmp = ft_strstr(line, "WE");
	if (ft_strlen(game->map->path_w)
		&& ft_strlen(game->tmp) && ft_strstr(game->tmp, game->map->path_w))
		game->err = 1;
	if (game->tmp != 0 && gm_h && !game->map->path_w)
	{
		game->map->path_w = ft_strtrim(game->tmp + 2, " \n");
		return (1);
	}
	return (0);
}

int	check_condition_ea(t_game *game, char *line, int gm_h)
{
	game->tmp = ft_strstr(line, "EA");
	if (ft_strlen(game->map->path_e)
		&& ft_strlen(game->tmp) && ft_strstr(game->tmp, game->map->path_e))
		game->err = 1;
	if (game->tmp != 0 && gm_h && !game->map->path_e)
	{
		game->map->path_e = ft_strtrim(game->tmp + 2, " \n");
		return (1);
	}
	return (0);
}
