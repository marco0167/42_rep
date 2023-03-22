#include "../so_long.h"

void	close_game(t_game *game, int code, char *str)
{
	int	i;

	if (code > 2)
	{
		mlx_destroy_image(game->mlx, game->sprites->collectable);
		mlx_destroy_image(game->mlx, game->sprites->floor);
		mlx_destroy_image(game->mlx, game->sprites->player);
		free(game->sprites);
	}
	if (code > 1)
	{
		i = 0;
		while (game->map.map[i])
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.name);
		free(game->map.map);
	}
	if (code > 0)
	{
		mlx_destroy_window(game->mlx, game->window);
		free(game);
	}
	ft_printf("%s\n", str);
	exit(0);
}
