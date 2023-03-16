#include "../so_long.h"

void	ft_is_collectable(t_game *game)
{
	if (game->map.map[game->player_pos.y][game->player_pos.x] == 'C')
	{
		game->collectable_get++;
		game->objects.collectable--;
	}
}
void	ft_is_exit(t_game *game, t_vector old_player_pos)
{
	if (game->map.map[game->player_pos.y][game->player_pos.x] == 'E')
		if (game->objects.collectable == 0)
			exit(0);
		else
			game->player_pos = old_player_pos;
}

int	input(int key, void *param)
{
	t_game	*game;
	t_vector	old_player_pos;

	game = (t_game *)param;
	old_player_pos = game->player_pos;
	mlx_clear_window(game->mlx, game->window);
	if (key == 53)
		exit(0);
	else if (key == 13 && (game->map.map[game->player_pos.y - 1][game->player_pos.x] != '1'))
		game->player_pos.y -= 1;
	else if (key == 1 && (game->map.map[game->player_pos.y + 1][game->player_pos.x] != '1'))
		game->player_pos.y += 1;
	else if (key == 0 && (game->map.map[game->player_pos.y][game->player_pos.x - 1] != '1'))
		game->player_pos.x -= 1;
	else if (key == 2 && (game->map.map[game->player_pos.y][game->player_pos.x + 1] != '1'))
		game->player_pos.x += 1;
	ft_is_collectable(game);
	ft_is_exit(game, old_player_pos);

	game->map.map[old_player_pos.y][old_player_pos.x] = '0';
	game->map.map[game->player_pos.y][game->player_pos.x] = 'P';
	print_map(game);
	ft_printf("key code: %d . %d\n", old_player_pos.x, old_player_pos.y);
	return (0);
}

