/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:50 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/31 16:38:33 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stacks	*alloc_stacks(t_stacks *stacks)
// {
// 	stacks = (t_stacks *)malloc(sizeof(t_stacks));
// 	return (stacks);
// }

// t_node	*alloc_list(t_node *node)
// {
// 	node = malloc(sizeof(t_node));
// 	return (node);
// }

int	main(int ac, char **av)
{
	int			len;
	t_stacks	stacks;

	len = ac - 1;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	printf("LEN: %d\n", len);
	check_error(av, len);
	// list_init(&stacks.stack_a, av, len);
	(void)av;
	ft_end(&stacks);
	return (0);
}
