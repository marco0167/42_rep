/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:53:50 by mcoppola          #+#    #+#             */
/*   Updated: 2023/06/05 17:27:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_cheaper(t_stacks *stacks);

void	ft_mov_alg(t_node *curr, t_node *prev, t_stacks *stacks)
{
	if (curr->pos != 0)
	{
		if (prev->pos != 0)
			ft_mov_alg_condition(curr, prev, stacks);
		else
		{
			if (curr->pos > (stacks->len_a / 2))
				ft_reverse_rotate_a(stacks, 1);
			else
				ft_rotate_a(stacks, 1);
		}
		ft_find_cheaper(stacks);
	}
	else if (curr->pos == 0 && prev->pos == 0)
		ft_push_b(stacks, 1);
	else
	{
		if (prev->pos > (stacks->len_b / 2))
			ft_reverse_rotate_b(stacks, 1);
		else
			ft_rotate_b(stacks, 1);
		ft_find_cheaper(stacks);
	}
}

t_node	*ft_search_prev_num(t_node **head, int data)
{
	t_node	*curr;

	curr = *head;
	while (curr != NULL)
	{
		if (curr->data == data)
			return (curr);
		curr = curr->next;
	}
	return (curr);
}

void	ft_find_cheaper(t_stacks *stacks)
{
	t_node	*current;
	t_node	*cheaper;

	current = stacks->stack_a;
	cheaper = stacks->stack_a;
	while (current != NULL)
	{
		if (current->cost < cheaper->cost)
			cheaper = current;
		current = current->next;
	}
	ft_mov_alg(cheaper, ft_search_prev_num(&stacks->stack_b, cheaper->prev_num),
		stacks);
}

void	ft_find_bigger_num(t_stacks *stacks)
{
	t_node	*current;
	t_node	*bigger;

	current = stacks->stack_b;
	bigger = stacks->stack_b;
	while (current != NULL)
	{
		if (current->data > bigger->data)
			bigger = current;
		current = current->next;
	}
	while (bigger->pos != 0)
	{
		if (bigger->pos > (stacks->len_b / 2))
			ft_reverse_rotate_b(stacks, 1);
		else
			ft_rotate_b(stacks, 1);
	}
}

void	ft_sorting_alg(t_stacks *stacks)
{
	ft_push_b(stacks, 1);
	ft_push_b(stacks, 1);
	while (stacks->stack_a != NULL)
	{
		ft_init_cost(&stacks->stack_a, &stacks->stack_b, stacks);
		ft_find_cheaper(stacks);
	}
	ft_find_bigger_num(stacks);
	while (stacks->stack_b != NULL)
		ft_push_a(stacks, 1);
}
