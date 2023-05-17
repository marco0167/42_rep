/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:33:24 by mcoppola          #+#    #+#             */
/*   Updated: 2023/05/17 11:57:51 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_node **head, int val, int index)
{
	t_node	*curr;
	t_node	*new;

	new = malloc(sizeof(t_node));
	curr = *head;
	if (!new)
		exit(1);
	new->data = val;
	new->pos = index;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
}

int	set_numbers(char **data, t_node **head)
{
	int	i;

	i = 0;
	while (data[i])
	{
		add_node_back(&*head, ft_atoi(data[i]), i);
		i++;
	}
	return (i);
}

void	list_init(t_stacks *stacks, char **data, int len)
{
	stacks->len_a = set_numbers(data, &stacks->stack_a);
}
