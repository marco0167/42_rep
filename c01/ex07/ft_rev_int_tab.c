/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:17:04 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/19 23:58:14 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	app;

	i = 0;
	while (i < size / 2)
	{
		app = tab[size - 1 - i];
		tab[size - 1 - i] = tab[i];
		tab[i] = app;
		i++;
	}	
}
