/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:50 by mcoppola          #+#    #+#             */
/*   Updated: 2023/06/05 17:47:18 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			len;
	t_stacks	stacks;
	char		**numbers;

	if (ac == 1)
		return (0);
	len = ac - 1;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.len_b = 0;
	stacks.moves = 0;
	numbers = check_error(av, len);
	list_init(&stacks, numbers, len);
	ft_moves(&stacks);
	(void)av;
	ft_end(&stacks, len, numbers);
	return (0);
}
