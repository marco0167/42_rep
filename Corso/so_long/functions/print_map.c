/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:56:40 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/16 18:45:36 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->wall, j * game->bit, i * game->bit);
			else if (game->map.map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->floor, j * game->bit, i * game->bit);
			else if (game->map.map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->floor, j * game->bit, i * game->bit);
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->player, j * game->bit, i * game->bit);
			}
			else if (game->map.map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->floor, j * game->bit, i * game->bit);
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->collectable, j * game->bit, i * game->bit);
			}
			else if (game->map.map[i][j] == 'E')
				{
					mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->floor, j * game->bit, i * game->bit);
					if (game->objects.collectable == 0)
						game->sprites->exit->door = mlx_xpm_file_to_image(game->mlx, "./assets_32/door_open.xpm", &game->bit, &game->bit);
					mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->exit->door_struct, j * game->bit, i * game->bit);
					mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->exit->door, j * game->bit, i * game->bit);
				}
			j++;
		}
		i++;
	}
}

void	sprite_assign(t_game *game)
{
	game->sprites = malloc(sizeof(t_sprites));
	game->sprites->exit = malloc(sizeof(t_exit));
	game->sprites->wall = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall.xpm", &game->bit, &game->bit);
	game->sprites->player = mlx_xpm_file_to_image(game->mlx, "./assets_32/player.xpm", &game->bit, &game->bit);
	game->sprites->floor = mlx_xpm_file_to_image(game->mlx, "./assets_32/floor.xpm", &game->bit, &game->bit);
	game->sprites->exit->door = mlx_xpm_file_to_image(game->mlx, "./assets_32/door_close.xpm", &game->bit, &game->bit);
	game->sprites->exit->door_struct = mlx_xpm_file_to_image(game->mlx, "./assets_32/door_struct.xpm", &game->bit, &game->bit);
	game->sprites->collectable = mlx_xpm_file_to_image(game->mlx, "./assets_32/collectable_1.xpm", &game->bit, &game->bit);
}
