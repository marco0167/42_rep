/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:47:56 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/17 15:04:08 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int i, int j, int k, int x)
{
	if (((i * 10) + j) < ((k * 10) + x))
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, " ", 1);
		write(1, &k, 1);
		write(1, &x, 1);
		if (!(i == '9' && j == '8' && k == '9' && x == '9'))
			write(1, ", ", 2);
	}
}

void	second_digit(int i, int j, int k, int x)
{
	while (k <= '9')
	{
		while (x <= '9')
		{
			print(i, j, k, x);
			x++;
		}
		x = '0';
		k++;
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;
	int	k;
	int	x;

	i = '0';
	j = '0';
	k = '0';
	x = '0';
	while (i <= '9')
	{
		while (j <= '9')
		{
			second_digit(i, j, k, x);
			k = '0';
			j++;
		}
		j = '0';
		i++;
	}
}
