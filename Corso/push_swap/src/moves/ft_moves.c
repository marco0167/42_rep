/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:42:36 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/17 17:56:06 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_moves(t_stacks *stacks)
{
	ft_push_b(stacks);
	ft_push_b(stacks);
	write(1, "------\n", 7);
	print_list(stacks);
	ft_swap_ss(stacks);
	write(1, "------\n", 7);
	print_list(stacks);
}
