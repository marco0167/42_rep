/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:33:24 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/18 12:25:01 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_node **head, int val)
{
	t_node	*curr;
	t_node	*new;

	new = malloc(sizeof(t_node));
	curr = *head;
	if (!new)
		exit(1);
	new->data = val;
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

void	set_numbers(char **data, t_node **head)
{
	int	i;

	i = 0;
	while (data[i])
		add_node_back(&*head, ft_atoi(data[i++]));
}

void	print_list(t_stacks *stacks)//funxzione da eliminareee
{
	t_node	*stacks_a;
	t_node	*stacks_b;

	stacks_a = stacks->stack_a;
	stacks_b = stacks->stack_b;
	write(1, "------\n", 7);
	write(1, "A    B\n", 7);
	while (stacks_a != NULL || stacks_b != NULL)
	{
		if (stacks_a != NULL && stacks_b != NULL)
		{
			printf("%d  %d\n", stacks_a->data, stacks_b->data);
			stacks_a = stacks_a->next;
			stacks_b = stacks_b->next;
		}
		else
		{
			if (stacks_a != NULL)
			{
				printf("%d\n", stacks_a->data);
				stacks_a = stacks_a->next;
			}
			else
				printf("    ");
			if (stacks_b != NULL)
			{
				printf("%d\n", stacks_b->data);
				stacks_b = stacks_b->next;
			}
		}
	}
}

void	list_init(t_stacks *stacks, char **data, int len)
{
	set_numbers(data, &stacks->stack_a);
}
