/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_length_calculator_helper.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:52 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:26:53 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	line_length_calcultor_helper_1(float *line_lenght, t_vector_int *end,
			t_vector_int start, float directionRadians)
{
	*line_lenght += 1;
	end->x = start.x + (int)(cos(directionRadians) * *line_lenght);
	end->y = start.y + (int)(sin(directionRadians) * *line_lenght);
}

void	line_length_calcultor_helper_2(float directionRadians, int *side)
{
	if (cos(directionRadians) < 0)
		*side = WE;
	else
		*side = EA;
}

void	line_length_calcultor_helper_3(float directionRadians, int *side)
{
	if (sin(directionRadians) < 0)
		*side = NO;
	else
		*side = SO;
}

void	line_length_calcultor_helper_4(t_game *game, t_vector_int end)
{
	int	temp;

	temp = end.x;
	while ((end.x / MAP_BIT) == (temp / MAP_BIT))
		temp --;
	temp++;
	game->ray_offset = end.x - temp;
}

void	line_length_calcultor_helper_5(t_game *game, t_vector_int end)
{
	int	temp;

	temp = end.y;
	while ((end.y / MAP_BIT) == (temp / MAP_BIT))
		temp --;
	temp++;
	game->ray_offset = end.y - temp;
}
