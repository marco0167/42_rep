/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:42:36 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/18 12:21:59 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_moves(t_stacks *stacks)
{
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_push_b(stacks);
	print_list(stacks);
	ft_rotate_rr(stacks);
	print_list(stacks);
	printf("mosse %d\n", stacks->moves);
}
