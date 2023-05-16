/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:12:27 by mcoppola          #+#    #+#             */
/*   Updated: 2023/05/03 14:25:06 by mcoppola         ###   ########.fr       */
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
	int				cost;
	int				prev_num;
	int				pos;
	struct s_node	*next;
}				t_node;

typedef struct s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		len_a;
	int		len_b;
	int		moves;
}				t_stacks;

//ft_atoi.c
int		ft_atoi(const char *str);

//list.c
void	list_init(t_stacks *stacks, char **data, int len);
void	add_node_back(t_node **head, int val, int index);
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
void	ft_swap_a(t_stacks *stacks, int flag);
void	ft_swap_b(t_stacks *stacks, int flag);
void	ft_swap_ss(t_stacks *stacks);

//ft_rotate
void	ft_rotate_a(t_stacks *stacks, int flag);
void	ft_rotate_b(t_stacks *stacks, int flag);
void	ft_rotate_rr(t_stacks *stacks);

//ft_reverse_rotate_a
void	ft_reverse_rotate_a(t_stacks *stacks, int flag);
void	ft_reverse_rotate_b(t_stacks *stacks, int flag);
void	ft_reverse_rotate_rrr(t_stacks *stacks);

//ft_moves
void	ft_moves(t_stacks *stacks);
void	ft_upg_pos_a(t_stacks *stacks);
void	ft_upg_pos_b(t_stacks *stacks);
int	ft_is_alrd_sorted(t_stacks *stacks);

//ft_sorting_alg
void	ft_sorting_alg(t_stacks *stacks);

//ft_small_sorting
void	ft_small_sorting(t_stacks *stacks);

//ft_medium_sorting
void	ft_medium_sorting(t_stacks *stacks);

//ft_set_cost
void	ft_set_cost_a(t_node **head, t_stacks *stacks);
void	ft_set_cost_b(t_node **head, int len);
void	ft_init_cost(t_node **stack_a, t_node **stack_b, t_stacks *stacks);
void	ft_find_prev_num(t_stacks *stacks);

#endif
