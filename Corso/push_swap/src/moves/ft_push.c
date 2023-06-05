/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:18:31 by mcoppola          #+#    #+#             */
/*   Updated: 2023/06/05 17:26:30 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_stacks *stacks, int flag)
{
	t_node	*node_to_move;

	node_to_move = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	node_to_move->next = stacks->stack_a;
	stacks->stack_a = node_to_move;
	stacks->len_a++;
	stacks->len_b--;
	stacks->moves++;
	ft_upg_pos_a(stacks);
	ft_upg_pos_b(stacks);
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	ft_push_b(t_stacks *stacks, int flag)
{
	t_node	*node_to_move;

	node_to_move = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	node_to_move->next = stacks->stack_b;
	stacks->stack_b = node_to_move;
	stacks->len_b++;
	stacks->len_a--;
	stacks->moves++;
	ft_upg_pos_a(stacks);
	ft_upg_pos_b(stacks);
	if (flag == 1)
		write(1, "pb\n", 3);
}
