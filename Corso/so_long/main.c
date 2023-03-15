/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:29:29 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/15 15:33:37 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	§*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 300, "Hello world!");
// 	img.img = mlx_new_image(mlx, 500, 300);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x0000FF00);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }


t_game	*ft_alloc_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	return (game);
}

int main(int argc, char **argv)
{
	t_game *game;

	game = ft_alloc_game(game);

	map_checker(game, argc, argv);
	set_map_matrix(game);
	ft_printf("Player position: %d, %d, alive: %d", game->player.position.x, game->player.position.y, game->player.alive);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.width * 32, game->map.height * 32, "Hello world!");
	mlx_loop(game->mlx);
}
