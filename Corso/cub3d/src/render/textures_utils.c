/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:27:09 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:27:10 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	rgb_to_hex(int rgb[3])
{
	return (((unsigned int)rgb[0] << 16)
		| ((unsigned int)rgb[1] << 8) | (unsigned int)rgb[2]);
}

unsigned int	get_color(t_texture *texture, int x, int y)
{
	int		color;

	color = (*(unsigned int *)(texture->addr + (4 * x) + (4 * 64 * y)));
	return (color);
}

void	create_texture_matrix(t_game *game, char *path, int text_i)
{
	int	y;
	int	x;

	game->texture->img = mlx_xpm_file_to_image(game->mlx, path,
			&game->texture->width, &game->texture->height);
	game->texture->addr = mlx_get_data_addr(game->texture->img,
			&game->texture->bpp, &game->texture->line_length,
			&game->texture->endian);
	x = 0;
	y = 0;
	game->col_mtrx_texts[text_i] = malloc(sizeof(unsigned int *) * IMG_SIZ);
	while (y < IMG_SIZ)
	{
		game->col_mtrx_texts[text_i][y] = malloc(sizeof(unsigned int)
				* IMG_SIZ);
		x = 0;
		while (x < IMG_SIZ)
		{
			game->col_mtrx_texts[text_i][y][x] = get_color(game->texture, x, y);
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, game->texture->img);
}
