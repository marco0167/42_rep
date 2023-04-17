/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:50 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/17 17:58:38 by mcoppola         ###   ########.fr       */
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
	char		**numbers;

	len = ac - 1;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.moves = 0;
	printf("LEN: %d\n", len);
	numbers = check_error(av, len);
	list_init(&stacks, numbers, len);
	ft_moves(&stacks);
	(void)av;
	ft_end(&stacks, len, numbers);
	return (0);
}
