/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:27:19 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:27:20 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/**
 * Round the passed value to the nearest value
 *
 * @param n: the number to round
 * @return the number rounded
*/
double	round(double n)
{
	return (floor(n + 0.5));
}

int	change_rangey(t_range r, int input)
{
	double	slope;
	int		adjusted_input;

	adjusted_input = input;
	if (input < r.start_iny)
		adjusted_input = (r.end_iny - r.start_iny) - input;
	else if (input > r.end_iny)
		adjusted_input = ((r.end_iny) * (int)(input
					/ (r.end_iny))) + r.start_iny - input;
	slope = 1.0 * (r.end_outy - r.start_outy)
		/ (r.end_iny - r.start_iny);
	return ((int)(r.start_outy + slope * (adjusted_input - r.start_iny)));
}

int	change_rangex(t_range r, int input)
{
	double	slope;
	int		adjusted_input;

	adjusted_input = input;
	if (input < r.start_inx)
		adjusted_input = (r.end_inx - r.start_inx) - input;
	else if (input > r.end_inx)
		adjusted_input = ((r.end_inx) * (int)(input
					/ (r.end_inx))) + r.start_inx - input;
	slope = 1.0 * (r.end_outx - r.start_outx)
		/ (r.end_inx - r.start_inx);
	return ((int)(r.start_outx + slope * (adjusted_input - r.start_inx)));
}
