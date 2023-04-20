/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:09:53 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/20 19:14:53 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_letter(char **numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len > 1)
		i = 1;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if (numbers[i][j] < '0' || numbers[i][j] > '9')
				if (numbers[i][j] != '-' && numbers[i][j] != '+')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_doubles(char **numbers)
{
	int	i;
	int	k;

	i = 0;
	while (numbers[i])
	{
		k = i + 1;
		while (numbers[k])
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[k]))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

char	**check_error(char **av, int len)
{
	char	**numbers;
	int		i;
	int		result;

	i = 0;
	if (len == 1)
		numbers = ft_split(av[1], ' ');
	else
		numbers = ++av;
	result = find_letter(numbers, len) + check_doubles(numbers);
	if (result > 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (numbers);
}
