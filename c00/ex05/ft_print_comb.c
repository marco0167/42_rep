/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:09:51 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/14 12:46:56 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printer(int i, int j, int k)
{
	if (i < j && i < k && j < k)
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
		if (i != '7')
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 48;
	j = 49;
	k = 50;
	while (i < 58)
	{
		while (j < 58)
		{
			while (k < 58)
			{
				ft_printer(i, j, k);
				k++;
			}
			j++;
			k = j;
		}
		i++;
		j = i;
	}
}
