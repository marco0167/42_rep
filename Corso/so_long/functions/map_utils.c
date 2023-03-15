/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:29:11 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/15 11:29:12 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*dimension_checker(t_game *game)
{
	int i;

	i = 0;
	while (game->map.map[i])
	{
		if (game->map.width != ft_strlen(game->map.map[i]))
			return ("map not rectangle");
		i++;
	}
	return (0);
}
