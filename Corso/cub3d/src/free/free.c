/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:24:57 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:24:58 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(t_map *map)
{
	if (map->path_n)
		free(map->path_n);
	if (map->path_s)
		free(map->path_s);
	if (map->path_e)
		free(map->path_e);
	if (map->path_w)
		free(map->path_w);
	if (map->color_f)
		free(map->color_f);
	if (map->color_c)
		free(map->color_c);
}

void	free_empty_game(t_game *game)
{
	free(game->texture);
	free(game->render);
	free(game->canva);
	free(game->map->p_pos);
	free(game->map);
	free(game);
}

void	free_map_matrix(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->map_matrix)
	{
		while (i < game->map->height)
		{
			free(game->map->map_matrix[i]);
			i++;
		}
		free(game->map->map_matrix);
	}
}

void	free_col_matrix_texts(t_game *game)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (c < 4)
	{
		i = 0;
		while (i < IMG_SIZ)
		{
			free(game->col_mtrx_texts[c][i]);
			i++;
		}
		free(game->col_mtrx_texts[c]);
		c++;
	}
}

void	free_game(t_game *game, short stage)
{
	if (stage > 3)
	{
		free_col_matrix_texts(game);
		mlx_destroy_image(game->mlx, game->canva->img);
	}
	if (stage > 2)
		free_map_matrix(game);
	if (stage > 1)
		free_map(game->map);
	if (stage > 0)
		free(game->map->name);
	free_empty_game(game);
}
