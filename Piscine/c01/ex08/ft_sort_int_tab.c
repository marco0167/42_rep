/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:59:46 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/20 01:13:49 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	max;
	int	c;	
	int	i;

	i = size - 1;
	c = 0;
	max = tab[0];
	while (i > 0)
	{
		while (c < size)
		{
			if (tab[c] > max)
				max = tab[c];
			else
			{
				tab[c - 1] = tab[c];
				tab[c] = max;
			}
			c++;
		}
		max = tab[0];
		c = 1;
		i--;
	}
}
