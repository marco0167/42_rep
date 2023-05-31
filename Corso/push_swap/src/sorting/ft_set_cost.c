/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:34:43 by mcoppola          #+#    #+#             */
/*   Updated: 2023/05/31 10:04:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_prev_num(t_stacks *stacks)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stacks->i = 0;
	stack_a = stacks->stack_a;
	while (stack_a != NULL)
	{
		stack_b = stacks->stack_b;
		find_prev_num_util1(stacks, stack_a, stack_b);
		find_prev_num_util2(stacks, stack_a, stack_b);
		stack_a = stack_a->next;
	}
}

void	ft_set_const_condition(t_node **current, int *cost, int *passed,
	t_stacks *stacks)
{
	if (*cost == ((stacks->len_a) / 2) && *passed != 1)
	{
		(*current)->cost = *cost + (*current)->cost;
		(*current) = (*current)->next;
		if (stacks->len_a % 2 == 1)
		{
			(*current)->cost = ++(*cost) + (*current)->cost;
			++(*cost);
		}
		else
			(*current)->cost = ++(*cost) + (*current)->cost;
		(*cost)--;
		*passed = 1;
	}
	else
	{
		if (*passed == 0)
			(*current)->cost = (*cost)++ + (*current)->cost;
		else
			(*current)->cost = (*cost)-- + (*current)->cost;
	}
}

void	ft_set_cost_a(t_node **head, t_stacks *stacks)
{
	t_node	*current;
	int		cost;
	int		passed;

	cost = 1;
	passed = 0;
	current = *head;
	while (current != NULL)
	{
		ft_set_const_condition(&current, &cost, &passed, stacks);
		current = current->next;
	}
}

void	ft_set_cost_b(t_node **head, int len)
{
	t_node	*current;
	int		cost;
	int		passed;

	cost = 1;
	passed = 0;
	current = *head;
	while (current != NULL)
	{
		ft_set_const_condition_b(&current, &cost, &passed, len);
		current = current->next;
	}
}

void	ft_init_cost(t_node **stack_a, t_node **stack_b, t_stacks *stacks)
{
	if (stack_a != NULL)
		init_cost_stack_a(stack_a);
	if (stack_b != NULL)
		init_cost_stack_b(stack_b, stacks);
	if (stack_a != NULL)
		ft_set_cost_a(&stacks->stack_a, stacks);
}
