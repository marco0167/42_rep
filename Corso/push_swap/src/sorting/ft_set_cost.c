/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:34:43 by mcoppola          #+#    #+#             */
/*   Updated: 2023/05/17 19:28:09 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_prev_num_utl1(t_node *stack_a, t_node *prev, t_stacks *stacks,
	t_node *stack_b)
{
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
		ft_set_cost_a(&stacks->stack_a, stacks);
}
