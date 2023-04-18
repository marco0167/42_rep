/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:18:31 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/18 12:17:05 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_stacks *stacks)
{
	t_node	*node_to_move;

	node_to_move = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	node_to_move->next = stacks->stack_a;
	stacks->stack_a = node_to_move;
	write(1, "pa\n", 3);
	stacks->moves++;
}

void	ft_push_b(t_stacks *stacks)
{
	t_node	*node_to_move;

	node_to_move = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	node_to_move->next = stacks->stack_b;
	stacks->stack_b = node_to_move;
	write(1, "pb\n", 3);
	stacks->moves++;
}
