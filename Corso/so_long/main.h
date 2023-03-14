/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:32:58 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/14 17:51:42 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>
# include "./get_next_line/get_next_line.h"

// typedef struct s_pos
// {
// 	int	x;
// 	int	y;
// }				t_pos;

typedef struct s_collectable
{
	int	qnt;
	int	collected;
}				t_collectable;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct s_game {
	t_map			map;
	t_collectable	collectable;
}				t_game;

void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strlen2(char *s);
char	*ft_strdup(const char *s1);
void	set_map_matrix(t_game *game);

# endif
