/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_alg_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:06:50 by mcoppola          #+#    #+#             */
/*   Updated: 2023/06/05 17:04:08 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_mov_alg_condition(t_node *curr, t_node *prev, t_stacks *stacks)
{
	if (curr->pos > (stacks->len_a / 2) && prev->pos
		> (stacks->len_b / 2))
		ft_reverse_rotate_rrr(stacks, 1);
	else if (curr->pos < (stacks->len_a / 2) && prev->pos
		> (stacks->len_b / 2))
	{
		ft_rotate_a(stacks, 1);
		ft_reverse_rotate_b(stacks, 1);
	}
	else if (curr->pos > (stacks->len_a / 2) && prev->pos
		< (stacks->len_b / 2))
	{
		ft_reverse_rotate_a(stacks, 1);
		ft_rotate_b(stacks, 1);
	}
	else if (curr->pos == (stacks->len_a / 2) && prev->pos
		<= (stacks->len_b / 2))
		ft_rotate_rr(stacks, 1);
	else if (curr->pos == (stacks->len_a / 2) && prev->pos
		>= (stacks->len_b / 2))
		ft_reverse_rotate_rrr(stacks, 1);
	else
		ft_rotate_rr(stacks, 1);
}
