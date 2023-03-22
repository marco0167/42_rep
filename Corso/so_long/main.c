/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:29:29 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/22 18:06:58 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_alloc_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	game->move_count = 0;
	game->objects.collectable = 0;
	game->objects.enemy = 0;
	game->objects.exit = 0;
	game->objects.player = 0;
	game->index = 0;
	game->enemy_dir = 0;
	return (game);
}

int main(int argc, char **argv)
{
	t_game *game;

	game = ft_alloc_game(game);
	game->bit = 32;
	map_checker(game, argc, argv);
	set_map_matrix(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.width * game->bit, game->map.height * game->bit, "Hello world!");
	sprite_assign(game);
	print_map(game);
	mlx_loop_hook(game->mlx, *ft_next_frame, game);
	mlx_key_hook(game->window, *input, game);
	mlx_loop(game->mlx);
}
