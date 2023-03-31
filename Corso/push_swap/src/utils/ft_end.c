/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:43:47 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/31 15:05:24 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

 void	free_node(t_node *node)
 {
	if (node->next != NULL)
		free_node(node->next);
	free(node);
 }

void	ft_end(t_stacks *stacks)
{
	if (stacks->stack_a)
		free_node(stacks->stack_a);
	if (stacks->stack_b)
		free_node(stacks->stack_b);
}
