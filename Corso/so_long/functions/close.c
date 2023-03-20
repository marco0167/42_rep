#include "../so_long.h"

void	close_game(t_game *game, int code, char *str)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->sprites->collectable);
	mlx_destroy_image(game->mlx, game->sprites->floor);
	mlx_destroy_image(game->mlx, game->sprites->player);
	// while (game->sprites->wall[i])
	// {
	// 	mlx_destroy_image(game->mlx, game->sprites->wall[i]);
	// 	i++;
	// }
	// i = 0;
	free(game->sprites->wall);
	free(game->sprites->exit);
	free(game->sprites);
	free(game->map.name);
	while (game->map.map[i])
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	mlx_destroy_window(game->mlx, game->window);
	free(game);
	
	ft_printf("%s\n", str);
	exit(0);
}
