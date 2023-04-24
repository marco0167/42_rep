/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:18:08 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/24 15:47:29 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_stacks *stacks, int flag)
{
	t_node	*head;
	t_node	*second_node;

	head = stacks->stack_a;
	second_node = stacks->stack_a->next;
	head->next = second_node->next;
	second_node->next = head;
	stacks->stack_a = second_node;
	stacks->moves++;
	ft_upg_pos_a(stacks);
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_stacks *stacks, int flag)
{
	t_node	*head;
	t_node	*second_node;

	head = stacks->stack_b;
	second_node = stacks->stack_b->next;
	head->next = second_node->next;
	second_node->next = head;
	stacks->stack_b = second_node;
	stacks->moves++;
	ft_upg_pos_b(stacks);
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_swap_ss(t_stacks *stacks)
{
	ft_swap_a(stacks, 0);
	ft_swap_b(stacks, 0);
	write(1, "ss\n", 3);
	stacks->moves--;
}
