/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:42:36 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/26 10:42:39 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_upg_pos_a(t_stacks *stacks)
{
	t_node	*current;
	int		pos_cntr;

	pos_cntr = 0;
	current = stacks->stack_a;
	while (current != NULL)
	{
		current->pos = pos_cntr++;
		current = current->next;
	}
}

void	ft_upg_pos_b(t_stacks *stacks)
{
	t_node	*current;
	int		pos_cntr;

	pos_cntr = 0;
	current = stacks->stack_b;
	while (current != NULL)
	{
		current->pos = pos_cntr++;
		current = current->next;
	}
}

int	ft_is_alrd_sorted(t_stacks *stacks)
{
	t_node	*current;

	current = stacks->stack_a;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_moves(t_stacks *stacks)
{
	// print_list(stacks);
	if (ft_is_alrd_sorted(stacks) == 1)
	{
		if (stacks->len_a < 4)
			ft_small_sorting(stacks);
		else if (stacks->len_a < 6)
			ft_medium_sorting(stacks);
		else
			ft_sorting_alg(stacks);
	}
	// print_list(stacks);
	// printf("mosse %d\n", stacks->moves);
}
