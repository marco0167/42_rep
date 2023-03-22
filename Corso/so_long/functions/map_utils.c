/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:29:11 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/22 15:26:13 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	dimension_checker(t_game *game)
{
	int i;

	i = 0;
	while (game->map.map[i])
	{
		if (game->map.width != ft_strlen(game->map.map[i]))
			close_game(game, 2, "map not rectangle");
		i++;
	}
}
