/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:35:43 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/25 12:42:38 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_medium_sorting(t_stacks *stacks)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*min;
	t_node	*max;

	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	min = stack_a;
	max = stack_a;
	ft_upg_pos_a(stacks);
	while (stack_a != NULL)
	{
		if (stack_a->data < min->data)
			min = stack_a;
		if (stack_a->data > max->data)
			max = stack_a;
		stack_a = stack_a->next;
	}
	stack_a = stacks->stack_a;
	while (stack_a != NULL)
	{
		if (stack_a == min || stack_a == max)
			if (stack_a->pos == 3)
				{
					ft_reverse_rotate_a(stacks);
					ft_push_b(stacks);
					if (stack_b == NULL)
					{
						ft_reverse_rotate_a(stacks);
						ft_push_b(stacks);
						break;
					}
				}
			else if (stack_a->pos = 0)
				ft_push_b(stacks);
			else if (stack_a->pos = 1)
			{
				ft_swap_a(stacks);
				ft_push_b(stacks);
			}
			else if (stack_a->pos == 2)
			{
				ft_rotate_a(stacks);
				ft_rotate_a(stacks);
				ft_push_b(stacks);
			}
		ft_upg_pos_a(stacks);
		stack_a = stack_a->next;
	}
}
