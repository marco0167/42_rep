/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:18:41 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/18 12:20:51 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_a(t_stacks *stacks)
{
	t_node	*head;
	t_node	*current;
	t_node	*last;

	head = stacks->stack_a;
	current = stacks->stack_a;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = head;
	stacks->stack_a = last;
	write(1, "rra\n", 4);
	stacks->moves++;
}

void	ft_reverse_rotate_b(t_stacks *stacks)
{
	t_node	*head;
	t_node	*current;
	t_node	*last;

	head = stacks->stack_b;
	current = stacks->stack_b;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = head;
	stacks->stack_b = last;
	write(1, "rrb\n", 4);
	stacks->moves++;
}

void	ft_reverse_rotate_rrr(t_stacks *stacks)
{
	ft_reverse_rotate_a(stacks);
	ft_reverse_rotate_b(stacks);
	write(1, "rrr\n", 4);
	stacks->moves--;
}
