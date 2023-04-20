/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:23:45 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/20 18:40:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_small_sorting(t_stacks *stacks)
{
	t_node	*head;

	head = stacks->stack_a;
	if (head->data > head->next->data)
	{
		if (head->next->data > head->next->next->data)
		{
			ft_rotate_a(stacks);
			ft_swap_a(stacks);
		}
		else if (head->data < head->next->next->data)
			ft_swap_a(stacks);
		else
			ft_rotate_a(stacks);
	}
	else if (head->data > head->next->next->data)
		ft_reverse_rotate_a(stacks);
	else
	{
		ft_reverse_rotate_a(stacks);
		ft_swap_a(stacks);
	}
}
