/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:18:16 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/24 15:48:08 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_a(t_stacks *stacks, int flag)
{
	t_node	*head;
	t_node	*current;

	head = stacks->stack_a;
	current = stacks->stack_a;
	while (current->next != NULL)
		current = current->next;
	stacks->stack_a = head->next;
	head->next = NULL;
	current->next = head;
	stacks->moves++;
	ft_upg_pos_a(stacks);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stacks *stacks, int flag)
{
	t_node	*head;
	t_node	*current;

	head = stacks->stack_b;
	current = stacks->stack_b;
	while (current->next != NULL)
		current = current->next;
	stacks->stack_b = head->next;
	head->next = NULL;
	current->next = head;
	stacks->moves++;
	ft_upg_pos_b(stacks);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	ft_rotate_rr(t_stacks *stacks)
{
	ft_rotate_a(stacks, 0);
	ft_rotate_b(stacks, 0);
	write(1, "rr\n", 3);
	stacks->moves--;
}
