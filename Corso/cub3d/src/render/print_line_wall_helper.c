/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_wall_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:27:05 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:27:06 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_line_wall_helper_1(t_game *game, float *line_length, float deg,
		t_print_line_wall_helper *var)
{
	var->ca = game->map->degree - deg;
	if (var->ca < 0)
		var->ca += 360;
	else if (var->ca > 360)
		var->ca -= 360;
	*line_length = *line_length * cos((var->ca * PI) / 180);
	var->height = ((MAP_BIT * 1.7) * WIN_HEIGHT) / *line_length;
}

void	print_line_wall_helper_2(t_game *game, float i,
		t_print_line_wall_helper *var)
{
	var->wall_start = (WIN_HEIGHT / 2) - (var->height / 2);
	var->wall_end = (WIN_HEIGHT / 2) + (var->height / 2);
	var->s_y = 0;
	var->s_x = (i * WIN_WIDTH) / game->render->fov;
	var->s_x_end = ((i + 1) * WIN_WIDTH) / game->render->fov;
	var->s_x_end -= (var->s_x_end - var->s_x) / 2;
	var->half_x = var->s_x_end - var->s_x;
	var->s_x -= var->half_x;
	if (var->s_x < 0)
		var->s_x = 0;
	var->wall_wd = var->height;
	var->start_x = var->s_x;
	var->offff = ((float)game->ray_offset * var->wall_wd) / MAP_BIT;
	var->wall_start = (WIN_HEIGHT / 2) - (var->height / 2);
	var->r.start_iny = var->wall_start;
	var->r.end_iny = var->wall_end;
	var->r.start_outy = 0;
	var->r.end_outy = game->texture->height - 1;
	var->r.start_inx = 0;
	var->r.end_inx = MAP_BIT - 1;
	var->r.start_outx = 0;
	var->r.end_outx = game->texture->width - 1;
}

void	print_line_wall_helper_3(t_game *game, float i, int side,
		t_print_line_wall_helper *var)
{
	var->tex_y = change_rangey(var->r, var->s_y);
	var->tex_x = change_rangex(var->r, game->ray_offset);
	if (side == NO)
		my_mlx_pixel_put(game->canva, var->s_x, var->s_y,
			game->col_mtrx_texts[NO][var->tex_y][var->tex_x]);
	else if (side == SO)
		my_mlx_pixel_put(game->canva, var->s_x, var->s_y,
			game->col_mtrx_texts[SO][var->tex_y][var->tex_x]);
	else if (side == WE)
		my_mlx_pixel_put(game->canva, var->s_x, var->s_y,
			game->col_mtrx_texts[WE][var->tex_y][var->tex_x]);
	else if (side == EA)
		my_mlx_pixel_put(game->canva, var->s_x, var->s_y,
			game->col_mtrx_texts[EA][var->tex_y][var->tex_x]);
}
