/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:53:50 by mcoppola          #+#    #+#             */
/*   Updated: 2023/05/16 19:24:38 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_cheaper(t_stacks *stacks);

void	ft_print_cost(t_node **head, char *text)//funzione da eliminare
{
	t_node	*current;

	current = *head;
	printf("\n----------------\n");
	printf("%s\n", text);
	while (current != NULL)
	{
		printf("COSTO DI %d = %d--PrevNum: %d--- POS-%d\n", current->data, current->cost, current->prev_num, current->pos
		);
		current = current->next;
	}
	// printf("COSTO DI %d = %d\n", current->data, current->cost);
}

void	ft_mov_alg(t_node *curr, t_node *prev, t_stacks *stacks)
{
	// if (curr->pos != 0 && prev->pos != 0)
	// {
	// 	if (curr->pos > (stacks->len_a / 2) && prev->pos >
	// 		(stacks->len_b / 2))
	// 		ft_reverse_rotate_rrr(stacks);
	// 	else if (curr->pos < (stacks->len_a / 2) && prev->pos <
	// 		(stacks->len_b / 2))
	// 		ft_rotate_rr(stacks);
	// 	ft_find_cheaper(stacks);
	// }
	// else if (curr->pos == 0 && prev->pos == 0)
	// 	ft_push_b(stacks);
	// else
	// {
	// 	if (curr->pos != 0)
	// 	{
	// 		if (curr->pos > (stacks->len_a / 2))
	// 			ft_reverse_rotate_a(stacks);
	// 		else
	// 			ft_rotate_a(stacks);
	// 	}
	// 	if (prev->pos != 0)
	// 	{
	// 		if (prev->pos > (stacks->len_b / 2))
	// 			ft_reverse_rotate_b(stacks);
	// 		else
	// 			ft_rotate_b(stacks);
	// 	}
	// 	ft_find_cheaper(stacks);
	// }

	if (curr->pos != 0)
	{
		if (prev->pos != 0)
		{
			if (curr->pos > (stacks->len_a / 2) && prev->pos >
				(stacks->len_b / 2))
				ft_reverse_rotate_rrr(stacks);
			else if (curr->pos < (stacks->len_a / 2) && prev->pos >
				(stacks->len_b / 2))
			{
				ft_rotate_a(stacks, 1);
				ft_reverse_rotate_b(stacks, 1);
			}
			else if (curr->pos > (stacks->len_a / 2) && prev->pos <
				(stacks->len_b / 2))
			{
				ft_reverse_rotate_a(stacks, 1);
				ft_rotate_b(stacks, 1);
			}
			else if (curr->pos == (stacks->len_a / 2) && prev->pos <=
				(stacks->len_b / 2))
				ft_rotate_rr(stacks);
			else if (curr->pos == (stacks->len_a / 2) && prev->pos >=
				(stacks->len_b / 2))
				ft_reverse_rotate_rrr(stacks);
			else{
				// printf("ROTATE a:%d, b:%d, lenA:%d, lenB%d\n", curr->pos, prev->pos, stacks->len_a, stacks->len_b);
				ft_rotate_rr(stacks);
			}

		}
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
		ft_push_b(stacks);
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

	// ft_init_cost(&stacks->stack_a, &stacks->stack_b, stacks);
	current = stacks->stack_a;
	cheaper = stacks->stack_a;
	while (current != NULL)
	{
		if (current->cost < cheaper->cost)
			cheaper = current;
		current = current->next;
	}
	// printf("b: %d\n", cheaper->prev_num);
	// printf("a: %d\n", cheaper->data);
	ft_mov_alg(cheaper, ft_search_prev_num(&stacks->stack_b, cheaper->prev_num),
				stacks);
	// printf("\nCheaper %d - %d - %d -%d\n", cheaper->data, cheaper->cost, cheaper->prev_num, cheaper->pos);
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
	ft_push_b(stacks);
	ft_push_b(stacks);

	while (stacks->stack_a != NULL)
	{
		ft_init_cost(&stacks->stack_a, &stacks->stack_b, stacks);
		ft_find_cheaper(stacks);
		// print_list(stacks);
		// ft_print_cost(&stacks->stack_a, "----STACK  A----");
		// ft_print_cost(&stacks->stack_b, "----STACK  B----");
	}
	ft_find_bigger_num(stacks);
	while (stacks->stack_b != NULL)
		ft_push_a(stacks);
}
