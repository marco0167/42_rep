/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:34:43 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/20 19:53:09 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_prev_num(t_stacks *stacks)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		prev;
	int		mvs;

	stack_a = stacks->stack_a;
	while (stack_a != NULL)
	{
		stack_b = stacks->stack_b;
		prev = stack_a->data;
		while (stack_b != NULL)
		{
			if (stack_b->data < stack_a->data)
				if (stack_b->data > prev || prev == stack_a->data)
				{
					prev = stack_b->data;
					mvs = stack_b->cost;
				}
			stack_b = stack_b->next;
		}
		if (prev == stack_a->data)
		{
			stack_b = stacks->stack_b;
			prev = stack_b->data;
			while (stack_b != NULL)
			{
				if (stack_b->data > prev)
				{
					prev = stack_b->data;
					mvs = stack_b->cost;
				}
				stack_b = stack_b->next;
			}
		}
		stack_a->prev_num = prev;
		stack_a->cost = mvs;
		stack_a = stack_a->next;
	}
}

void	ft_set_const_condition(t_node **current, int *cost, int *passed,
	int len)
{
	if (*cost == ((len) / 2) && *passed != 1)
	{
		(*current)->cost = *cost + (*current)->cost;
		(*current) = (*current)->next;
		if (len % 2 == 1)
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

void	ft_set_cost_a(t_node **head, int len)
{
	t_node	*current;
	int		cost;
	int		passed;

	cost = 1;
	passed = 0;
	current = *head;
	while (current != NULL)
	{
		ft_set_const_condition(&current, &cost, &passed, len);
		current = current->next;
	}
	// current->cost = cost + current->cost;
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
	// current->cost = cost - 1;
}

void	ft_init_cost(t_node **stack_a, t_node **stack_b, t_stacks *stacks)
{
	t_node	*current;

	if (stack_a != NULL)
	{
		current = *stack_a;
		while (current != NULL)
		{
			current->cost = 0;
			current->prev_num = 0;
			current = current->next;
		}
	}
	if (stack_b != NULL)
	{
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
	if (stack_a != NULL)
		ft_set_cost_a(&stacks->stack_a, stacks->len_a);
}
