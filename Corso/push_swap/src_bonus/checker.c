/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:29 by mcoppola          #+#    #+#             */
/*   Updated: 2023/06/05 17:49:29 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "./get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_error(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	ft_end(stacks, 0, NULL);
}

void	ft_check_moves(t_stacks *stacks, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		ft_swap_a(stacks, 0);
	else if (ft_strcmp(move, "sb\n") == 0)
		ft_swap_b(stacks, 0);
	else if (ft_strcmp(move, "ss\n") == 0)
		ft_swap_ss(stacks, 0);
	else if (ft_strcmp(move, "pa\n") == 0)
		ft_push_a(stacks, 0);
	else if (ft_strcmp(move, "pb\n") == 0)
		ft_push_b(stacks, 0);
	else if (ft_strcmp(move, "ra\n") == 0)
		ft_rotate_a(stacks, 0);
	else if (ft_strcmp(move, "rb\n") == 0)
		ft_rotate_b(stacks, 0);
	else if (ft_strcmp(move, "rr\n") == 0)
		ft_rotate_rr(stacks, 0);
	else if (ft_strcmp(move, "rra\n") == 0)
		ft_reverse_rotate_a(stacks, 0);
	else if (ft_strcmp(move, "rrb\n") == 0)
		ft_reverse_rotate_b(stacks, 0);
	else if (ft_strcmp(move, "rrr\n") == 0)
		ft_reverse_rotate_rrr(stacks, 0);
	else
		ft_error(stacks);
}

void	ft_checker(t_stacks *stacks)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		ft_check_moves(stacks, move);
		free(move);
		move = get_next_line(0);
	}
	free(move);
}

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
	ft_checker(&stacks);
	if (!ft_is_alrd_sorted(&stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_end(&stacks, len, numbers);
	return (0);
}
