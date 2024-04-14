/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:24:48 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:24:49 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_close_game(t_game *game, short stage, char *message)
{
	printf("%s%s%s\n", RED, message, RESET);
	free_game(game, stage);
	exit(1);
}

int	ft_end_game(t_game *game)
{
	ft_close_game(game, 4, "");
	return (0);
}
