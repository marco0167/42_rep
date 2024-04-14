/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:27:25 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:27:26 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_game *game)
{
	create_texture_matrix(game, game->map->path_n, NO);
	create_texture_matrix(game, game->map->path_e, EA);
	create_texture_matrix(game, game->map->path_s, SO);
	create_texture_matrix(game, game->map->path_w, WE);
	game->hex_col_c = rgb_to_hex(game->map->color_c);
	game->hex_col_f = rgb_to_hex(game->map->color_f);
}

t_game	*ft_alloc_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	game->canva = malloc(sizeof(t_image));
	game->render = malloc(sizeof(t_render));
	game->texture = malloc(sizeof(t_texture));
	game->map = malloc(sizeof(t_map));
	game->map->p_pos = malloc(sizeof(t_vector));
	game->map->path_n = NULL;
	game->map->path_s = NULL;
	game->map->path_e = NULL;
	game->map->path_w = NULL;
	game->map->color_f = NULL;
	game->map->color_c = NULL;
	game->px_mv = 1;
	game->map->height = 0;
	game->map->width = 0;
	game->render->fov = 60;
	game->movespeed = MOVESPEED;
	game->mouse_x_pos = WIN_WIDTH / 2;
	game->err = 0;
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_alloc_game(game);
	ft_map_checker(game, argc, argv);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "papon3D");
	game->canva->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->canva->addr = mlx_get_data_addr(game->canva->img,
			&game->canva->bits_per_pixel, &game->canva->line_length,
			&game->canva->endian);
	mlx_mouse_move(game->mlx, game->window, game->mouse_x_pos, WIN_HEIGHT / 2);
	mlx_mouse_hide(game->mlx, game->window);
	minimap_init(game);
	load_texture(game);
	mlx_hook(game->window, 6, 1L << 6, on_mouse_move, game);
	mlx_hook(game->window, 2, 1L << 0, on_input, game);
	mlx_hook(game->window, 17, 0, ft_end_game, game);
	mlx_loop(game->mlx);
}
