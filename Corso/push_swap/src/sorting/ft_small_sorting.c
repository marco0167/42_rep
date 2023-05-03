/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:23:45 by mcoppola          #+#    #+#             */
/*   Updated: 2023/05/03 10:21:38 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_small_sorting(t_stacks *stacks)
{
	t_node	*head;

	if (ft_is_alrd_sorted(stacks) == 1)
	{
		head = stacks->stack_a;
		if (head->data > head->next->data)
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
