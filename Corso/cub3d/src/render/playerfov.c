/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerfov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:27:02 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:27:03 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	line_length_calcultor(t_game *game, t_vector_int start,
	float directionRadians, int *side)
{
	float			line_lenght;
	t_vector_int	end;

	line_lenght = 0;
	end.x = start.x + (int)(cos(directionRadians) * line_lenght);
	end.y = start.y + (int)(sin(directionRadians) * line_lenght);
	while (game->map->map_matrix[(end.y / MAP_BIT)][(end.x / MAP_BIT)] != '1')
		line_length_calcultor_helper_1(&line_lenght, &end, start,
			directionRadians);
	if (game->map->map_matrix[((end.y + 1) / MAP_BIT)][(end.x / MAP_BIT)] ==
		'1' && game->map->map_matrix[((end.y - 1) / MAP_BIT)]
		[(end.x / MAP_BIT)] == '1')
		line_length_calcultor_helper_2(directionRadians, side);
	else if (game->map->map_matrix[(end.y / MAP_BIT)][((end.x + 1) / MAP_BIT)]
		== '1' && game->map->map_matrix[(end.y / MAP_BIT)]
		[((end.x - 1) / MAP_BIT)] == '1')
		line_length_calcultor_helper_3(directionRadians, side);
	if (*side == NO || *side == SO)
		line_length_calcultor_helper_4(game, end);
	else if (*side == WE || *side == EA)
		line_length_calcultor_helper_5(game, end);
	line_lenght -= 1;
	return (line_lenght);
}

int	print_px_map_helper(int x, int y)
{
	if (x >= MAP_START_X + (MAP_WIDTH / 2) - (MAP_BIT / 4)
		&& x <= MAP_START_X + (MAP_WIDTH / 2) + (MAP_BIT / 4)
		&& y >= MAP_START_Y + (MAP_WIDTH / 2) - (MAP_BIT / 4)
		&& y <= MAP_START_Y + (MAP_WIDTH / 2) + (MAP_BIT / 4))
		return (1);
	return (0);
}

void	print_px_map(t_game *game, int x, int y)
{
	t_print_px_map_helper	var;

	var.x2 = game->map->p_pos->x - (MAP_WIDTH / 2);
	var.y2 = game->map->p_pos->y - (MAP_HEIGHT / 2);
	var.calc_x = (var.x2 + x - MAP_START_X) / MAP_BIT;
	var.calc_y = (var.y2 + y - MAP_START_Y) / MAP_BIT;
	if (x == MAP_START_X || x == MAP_START_X + MAP_WIDTH || y == MAP_START_Y
		|| y == MAP_START_Y + MAP_HEIGHT)
		my_mlx_pixel_put(game->canva, x, y, COLOR_RED);
	else if (var.calc_x >= game->map->width || var.calc_y
		>= game->map->height - 1 || var.calc_x < 0 || var.calc_y < 0)
		my_mlx_pixel_put(game->canva, x, y, COLOR_BLACK);
	else if (game->map->map_matrix[var.calc_y][var.calc_x] == '1')
		my_mlx_pixel_put(game->canva, x, y, COLOR_YELLOW);
	else if (print_px_map_helper(x, y))
		my_mlx_pixel_put(game->canva, x, y, COLOR_GREEN);
	else if (game->map->map_matrix[var.calc_y][var.calc_x] == 'C'
			|| game->map->map_matrix[var.calc_y][var.calc_x] == 'O')
		my_mlx_pixel_put(game->canva, x, y, COLOR_PURPLE);
	else if (game->map->map_matrix[var.calc_y][var.calc_x] == '0'
			|| is_player(game->map->map_matrix[var.calc_y][var.calc_x]))
		my_mlx_pixel_put(game->canva, x, y, TEMP_FLOOR);
	else
		my_mlx_pixel_put(game->canva, x, y, COLOR_BLACK);
}

void	print_line_wall( t_game *game, float deg,
		float line_length, int side)
{
	t_print_line_wall_helper	var;

	print_line_wall_helper_1(game, &line_length, deg, &var);
	print_line_wall_helper_2(game, game->tmp_float, &var);
	while (var.s_x < WIN_WIDTH && var.s_x < var.s_x_end)
	{
		var.s_y = 0;
		while (var.s_y < WIN_HEIGHT)
		{
			if (var.s_x >= MAP_START_X && var.s_x <= (MAP_START_X + MAP_WIDTH)
				&& var.s_y >= MAP_START_Y && var.s_y
				<= (MAP_START_Y + MAP_HEIGHT))
				print_px_map(game, var.s_x, var.s_y);
			else if (var.s_y >= var.wall_start && var.s_y <= var.wall_end)
				print_line_wall_helper_3(game, game->tmp_float, side, &var);
			else if (var.s_y < (WIN_HEIGHT / 2))
				my_mlx_pixel_put(game->canva, var.s_x, var.s_y,
					game->hex_col_c);
			else
				my_mlx_pixel_put(game->canva, var.s_x, var.s_y,
					game->hex_col_f);
			var.s_y++;
		}
		var.s_x++;
	}
}

void	draw_straight_line_from_player(t_game *game, float directionDegrees)
{
	float			directionradians;
	float			all_degree;
	t_vector_int	start;
	int				side;
	int				val;

	game->tmp_float = 0;
	side = 0;
	all_degree = directionDegrees - game->render->fov / 2;
	while (all_degree <= directionDegrees + game->render->fov / 2)
	{
		start.x = game->map->p_pos->x;
		start.y = game->map->p_pos->y;
		directionradians = (all_degree * PI) / 180.0;
		val = line_length_calcultor(game, start, directionradians, &side);
		print_line_wall(game, all_degree, val, side);
		all_degree += 0.25;
		game->tmp_float += 0.25;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->canva->img, 0, 0);
}
