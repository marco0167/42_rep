/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:23:45 by mcoppola          #+#    #+#             */
/*   Updated: 2023/06/05 15:42:41 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_small_sorting_utils(t_stacks *stacks, t_node *head)
{
	if (stacks->len_a == 2)
		ft_swap_a(stacks, 1);
	else
	{
		if (head->data > head->next->data)
		{
			if (head->next->data > head->next->next->data)
			{
				ft_rotate_a(stacks, 1);
				ft_swap_a(stacks, 1);
			}
			else if (head->data < head->next->next->data)
				ft_swap_a(stacks, 1);
			else
				ft_rotate_a(stacks, 1);
		}
		else if (head->data > head->next->next->data)
			ft_reverse_rotate_a(stacks, 1);
		else
		{
			ft_reverse_rotate_a(stacks, 1);
			ft_swap_a(stacks, 1);
		}
	}
}

void	ft_small_sorting(t_stacks *stacks)
{
	t_node	*head;

	if (ft_is_alrd_sorted(stacks) == 1)
	{
		head = stacks->stack_a;
		ft_small_sorting_utils(stacks, head);
	}
}
