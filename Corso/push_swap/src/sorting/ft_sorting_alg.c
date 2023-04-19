/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:53:50 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/19 11:21:07 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_cost(t_node **head, char *text)//funzione da eliminare
{
	t_node	*current;

	current = *head;
	printf("\n----------------\n");
	printf("%s\n", text);
	while (current != NULL)
	{
		printf("COSTO DI %d = %d--PrevNum: %d\n", current->data, current->cost, current->prev_num);
		current = current->next;
	}
	// printf("COSTO DI %d = %d\n", current->data, current->cost);
}

// void	ft_find_prev_nb()

void	ft_sorting_alg(t_stacks *stacks)
{
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_push_b(stacks);
	ft_init_cost(&stacks->stack_a, &stacks->stack_a, stacks);
	ft_print_cost(&stacks->stack_a, "----STACK  A----");
	ft_print_cost(&stacks->stack_b, "----STACK  B----");
}
