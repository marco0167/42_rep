/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:34:43 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/18 17:10:48 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	while (current->next != NULL)
	{
		ft_set_const_condition(&current, &cost, &passed, len);
		current = current->next;
	}
	current->cost = cost + current->cost;
}

void	ft_set_cost_b(t_node **head, int len)
{
	t_node	*current;
	int		cost;
	int		passed;

	cost = 1;
	passed = 0;
	current = *head;
	while (current->next != NULL)
	{
		ft_set_const_condition_b(&current, &cost, &passed, len);
		current = current->next;
	}
	current->cost = cost - 1;
}

void	ft_init_cost(t_node **head)
{
	t_node	*current;

	current = *head;
	while (current->next != NULL)
	{
		current->cost = 0;
		current = current->next;
	}
	current->cost = 0;
}
