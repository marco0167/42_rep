/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:53:50 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/18 16:51:19 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_cost(t_node **head)
{
	t_node	*current;

	current = *head;
	printf("----------------\n");
	while (current->next != NULL)
	{
		printf("COSTO DI %d = %d\n", current->data, current->cost);
		current = current->next;
	}
	printf("COSTO DI %d = %d\n", current->data, current->cost);
}

// void	ft_find_prev_nb()

void	ft_sorting_alg(t_stacks *stacks)
{
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_init_cost(&stacks->stack_a);
	ft_init_cost(&stacks->stack_b);
	ft_set_cost_b(&stacks->stack_b, stacks->len_b);
	ft_set_cost_a(&stacks->stack_a, stacks->len_a);
	ft_print_cost(&stacks->stack_a);
	ft_print_cost(&stacks->stack_b);
}
