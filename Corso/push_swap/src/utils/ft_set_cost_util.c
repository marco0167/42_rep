/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:36:07 by codespace         #+#    #+#             */
/*   Updated: 2023/05/31 10:04:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_prev_num_util1(t_stacks *stacks, t_node *stack_a, t_node *stack_b)
{
	t_node	*prev;

	prev = stack_a;
	while (stack_b != NULL)
	{
		if (stack_b->data < stack_a->data)
		{
			if (stack_b->data > prev->data || prev->data == stack_a->data)
			{
				prev = stack_b;
				stacks->i = stack_b->cost;
			}
		}
		stack_b = stack_b->next;
	}
}

void	find_prev_num_util2(t_stacks *stacks, t_node *stack_a, t_node *stack_b)
{
	t_node	*prev;

	if (prev->data == stack_a->data)
	{
		stack_b = stacks->stack_b;
		prev = stack_b;
		while (stack_b != NULL)
		{
			if (stack_b->data > prev->data)
			{
				prev = stack_b;
				stacks->i = stack_b->cost;
			}
			stack_b = stack_b->next;
		}
	}
	stack_a->prev_num = prev->data;
	stack_a->cost = stacks->i;
}

void	ft_set_const_condition_b(t_node **current, int *cost, int *passed,
	int len)
{
	if (*cost == ((len) / 2) && *passed != 1)
	{
		(*current)->cost = *cost - 1;
		(*current) = (*current)->next;
		if (len % 2 == 1)
		{
			(*current)->cost = ++(*cost) - 1;
			++(*cost);
		}
		else
			(*current)->cost = ++(*cost) - 1;
		(*cost)--;
		*passed = 1;
	}
	else
	{
		if (*passed == 0)
			(*current)->cost = (*cost)++ - 1;
		else
			(*current)->cost = (*cost)-- - 1;
	}
}

void	init_cost_stack_a(t_node **stack_a)
{
	t_node	*current;

	current = *stack_a;
	while (current != NULL)
	{
		current->cost = 0;
		current->prev_num = 0;
		current = current->next;
	}
}

void	init_cost_stack_b(t_node **stack_b, t_stacks *stacks)
{
	t_node	*current;

	current = *stack_b;
	while (current != NULL)
	{
		current->cost = 0;
		current->prev_num = 0;
		current = current->next;
	}
	ft_set_cost_b(&stacks->stack_b, stacks->len_b);
	ft_find_prev_num(stacks);
}
