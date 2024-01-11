/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:59:51 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/11 17:46:39 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_valid_input(int ac, char **av)
{
	int	i;
	int	j;

	i = ac - 1;
	while (i > 0)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

void	ft_validity_checker(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf(STR_USAGE);
		exit(1);
	}
	if (!is_valid_input(ac, av))
	{
		printf(STR_ERR_INPUT);
		exit(1);
	}
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > MAX_PHILOS)
	{
		printf(STR_ERR_NUM_PHILOS);
		exit(1);
	}
}
