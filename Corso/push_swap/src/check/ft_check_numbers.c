/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:09:53 by mcoppola          #+#    #+#             */
/*   Updated: 2023/04/17 16:37:31 by mcoppola         ###   ########.fr       */
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
				return (1);
			j++;
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
	result = find_letter(numbers, len);
	if (result == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (numbers);
}
