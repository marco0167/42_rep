/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:33:24 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/17 16:31:44 by mcoppola         ###   ########.fr       */
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

void	print_list(t_node **head)//funxzione da eliminareee
{
	t_node	*current;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

void	list_init(t_node **head, char **data, int len)
{
	set_numbers(data, &*head);
	print_list(&*head);
}
