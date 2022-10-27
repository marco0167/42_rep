/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:57:53 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/16 18:47:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	check(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1))
		ft_putchar('o');
	else if ((j == 0 && i == y - 1) || (j == x - 1 && i == 0))
		ft_putchar('o');
	else if ((i == 0 || i == y - 1) && (j > 0 && j < x - 1))
		ft_putchar('-');
	else if ((j == 0 || j == x - 1) && (i > 0 && i < y - 1))
		ft_putchar('|');
	else
		ft_putchar(' ');
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
		while (i < y)
		{
			while (j < x)
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
