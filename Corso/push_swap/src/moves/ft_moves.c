/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:42:36 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/18 13:09:48 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_moves(t_stacks *stacks)
{
	print_list(stacks);
	ft_sorting_alg(stacks);
	print_list(stacks);
	printf("mosse %d\n", stacks->moves);
}
