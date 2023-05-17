/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:35:43 by mcoppola          #+#    #+#             */
/*   Updated: 2023/05/17 11:57:29 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_medium_sorting(t_stacks *stacks)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*min;
	t_node	*max;
	t_node	*next;

	stack_a = stacks->stack_a;
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
		next = stack_a->next;
		stack_b = stacks->stack_b;
		if (stack_a == min || stack_a == max)
		{
			if (stack_a->pos == 0)
				ft_push_b(stacks);
			else if (stack_a->pos == 3)
			{
				ft_reverse_rotate_a(stacks, 1);
				ft_push_b(stacks);
				if (stack_b == NULL)
				{
					ft_reverse_rotate_a(stacks, 1);
					ft_push_b(stacks);
					break ;
				}
			}
			else if (stack_a->pos == 1)
			{
				ft_swap_a(stacks, 1);
				ft_push_b(stacks);
			}
			else if (stack_a->pos == 2)
			{
				ft_rotate_a(stacks, 1);
				ft_rotate_a(stacks, 1);
				ft_push_b(stacks);
			}
		}
		ft_upg_pos_a(stacks);
		stack_a = next;
	}
	ft_small_sorting(stacks);
	stack_b = stacks->stack_b;
	if (stack_b->data > stack_b->next->data)
		ft_swap_b(stacks, 1);
	ft_push_a(stacks);
	ft_push_a(stacks);
	ft_rotate_a(stacks, 1);
}
