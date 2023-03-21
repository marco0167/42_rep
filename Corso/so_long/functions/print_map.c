/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:56:40 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/21 13:25:28 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_wall(t_game *game, int i, int j)
{
	printf("i: %d -- j: %d\n", i, j);
	if (i == 0 && j == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[4], j * game->bit, i * game->bit);
	else if (i == 0 && j == game->map.width - 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[5], j * game->bit, i * game->bit);
	else if (i == game->map.height - 1 && j == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[7], j * game->bit, i * game->bit);
	else if (i == game->map.height - 1 && j == game->map.width - 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[6], j * game->bit, i * game->bit);
	else if (i == 0 )
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[1], j * game->bit, i * game->bit);
	else if (j == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[0], j * game->bit, i * game->bit);
	else if (i == game->map.height - 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[3], j * game->bit, i * game->bit);
	else if (j == game->map.width - 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[2], j * game->bit, i * game->bit);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall[3], j * game->bit, i * game->bit);
	printf("porcoddiooooooooooooooooooooooo\n");
}

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
			{
				printf("porcoddio 1\n");
				print_wall(game, i, j);
			}
			else if (game->map.map[i][j] == '0')
			{
				printf("porcoddio 2\n");
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->floor, j * game->bit, i * game->bit);
			}
			else if (game->map.map[i][j] == 'P')
			{
				printf("porcoddio 3\n");
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->floor, j * game->bit, i * game->bit);
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->player, j * game->bit, i * game->bit);
			}
			else if (game->map.map[i][j] == 'C')
			{
				printf("porcoddio 4\n");
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->floor, j * game->bit, i * game->bit);
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites->collectable, j * game->bit, i * game->bit);
			}
			else if (game->map.map[i][j] == 'E')
			{
				printf("porcoddio 5\n");
				mlx_put_image_to_window(game->mlx, game->window,
				game->sprites->floor, j * game->bit, i * game->bit);
				if (game->objects.collectable == 0)
				{
					printf("speciale porcoddio\n");
					game->sprites->exit[1] = mlx_xpm_file_to_image(game->mlx, "./assets_32/exit/door_open.xpm", &game->bit, &game->bit);
				}
				mlx_put_image_to_window(game->mlx, game->window,
				game->sprites->exit[1], j * game->bit, i * game->bit);
				mlx_put_image_to_window(game->mlx, game->window,
				game->sprites->exit[0], j * game->bit, i * game->bit);
			}
			j++;
		}
		i++;
	}
}

void	sprite_assign(t_game *game)
{
	game->sprites = malloc(sizeof(t_sprites));
	game->sprites->wall[0] = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall/wall_0.xpm", &game->bit, &game->bit);
	game->sprites->wall[1] = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall/wall_1.xpm", &game->bit, &game->bit);
	game->sprites->wall[2] = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall/wall_2.xpm", &game->bit, &game->bit);
	game->sprites->wall[3] = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall/wall_3.xpm", &game->bit, &game->bit);
	game->sprites->wall[4] = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall/angle_0.xpm", &game->bit, &game->bit);
	game->sprites->wall[5] = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall/angle_1.xpm", &game->bit, &game->bit);
	game->sprites->wall[6] = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall/angle_2.xpm", &game->bit, &game->bit);
	game->sprites->wall[7] = mlx_xpm_file_to_image(game->mlx, "./assets_32/wall/angle_3.xpm", &game->bit, &game->bit);
	game->sprites->player = mlx_xpm_file_to_image(game->mlx, "./assets_32/player.xpm", &game->bit, &game->bit);
	game->sprites->floor = mlx_xpm_file_to_image(game->mlx, "./assets_32/floor.xpm", &game->bit, &game->bit);
	game->sprites->exit[0] = mlx_xpm_file_to_image(game->mlx, "./assets_32/exit/door_struct.xpm", &game->bit, &game->bit);
	game->sprites->exit[1] = mlx_xpm_file_to_image(game->mlx, "./assets_32/exit/door_close.xpm", &game->bit, &game->bit);
	game->sprites->collectable = mlx_xpm_file_to_image(game->mlx, "./assets_32/collectable_1.xpm", &game->bit, &game->bit);
}
