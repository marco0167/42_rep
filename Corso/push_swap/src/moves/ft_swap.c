/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:18:08 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/17 17:57:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_stacks *stacks)
{
	t_node	*head;
	t_node	*second_node;

	head = stacks->stack_a;
	second_node = stacks->stack_a->next;
	head->next = second_node->next;
	second_node->next = head;
	stacks->stack_a = second_node;
	stacks->moves++;
}

void	ft_swap_b(t_stacks *stacks)
{
	t_node	*head;
	t_node	*second_node;

	head = stacks->stack_b;
	second_node = stacks->stack_b->next;
	head->next = second_node->next;
	second_node->next = head;
	stacks->stack_b = second_node;
	stacks->moves++;
}

void	ft_swap_ss(t_stacks *stacks)
{
	ft_swap_a(stacks);
	ft_swap_b(stacks);
	stacks->moves--;
}
