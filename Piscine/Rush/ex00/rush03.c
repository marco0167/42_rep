/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:10:28 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/16 18:45:50 by azangril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	check(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == x - 1 && j == 0))
		ft_putchar('A');
	else if ((i == 0 && j == y - 1) || (i == x - 1 && j == y - 1))
		ft_putchar('C');
	else
	{
		if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
			ft_putchar ('B');
		else
			ft_putchar(' ');
	}
}

int	error_check(int x, int y)
{
	if ((x && (x > 0 && x <= 2147483647) && (y && (y > 0 && y <= 2147483647))))
		return (1);
	write(1, "Il numero inserito e' minore di 1 o non di tipo int", 51);
	return (0);
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (error_check(x, y) != 0)
	{
		i = 0;
		j = 0;
		while (i < x)
		{
			while (j < y)
			{
				check(i, j, x, y);
				j++;
			}
			i++;
			ft_putchar('\n');
			j = 0;
		}
	}
}
