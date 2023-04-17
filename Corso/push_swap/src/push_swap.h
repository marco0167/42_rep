/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:12:27 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/17 17:56:45 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

typedef struct s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		moves;
}				t_stacks;

//ft_atoi.c
int		ft_atoi(const char *str);

//list.c
void	list_init(t_stacks *stacks, char **data, int len);
void	add_node_back(t_node **head, int val);
void	print_list(t_stacks *stacks);

//-------- utils/ ----------
//ft_end.c
void	ft_end(t_stacks *stacks, int len, char **numbers);

//ft_split.c
char	**ft_split(char const *s, char c);

//ft_check_numbers.c
char	**check_error(char **av, int len);

//ft_push
void	ft_push_a(t_stacks *stacks);
void	ft_push_b(t_stacks *stacks);

//ft_swap
void	ft_swap_a(t_stacks *stacks);
void	ft_swap_b(t_stacks *stacks);
void	ft_swap_ss(t_stacks *stacks);

//ft_moves
void	ft_moves(t_stacks *stacks);

#endif