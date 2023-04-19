/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:42:36 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/19 16:20:45 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_upg_pos_a(t_stacks *stacks)
{
	t_node	*current;
	int		pos_cntr;

	pos_cntr = 0;
	current = stacks->stack_a;
	while (current != NULL)
	{
		current->pos = pos_cntr++;
		current = current->next;
	}
}

void	ft_upg_pos_b(t_stacks *stacks)
{
	t_node	*current;
	int		pos_cntr;

	pos_cntr = 0;
	current = stacks->stack_b;
	while (current != NULL)
	{
		current->pos = pos_cntr++;
		current = current->next;
	}
}

void	ft_moves(t_stacks *stacks)
{
	print_list(stacks);
	ft_sorting_alg(stacks);
	print_list(stacks);
	printf("mosse %d\n", stacks->moves);
}
