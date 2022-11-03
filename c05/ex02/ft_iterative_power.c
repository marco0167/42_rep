/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:15:25 by mcoppola          #+#    #+#             */
/*   Updated: 2022/11/02 15:52:02 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (nb < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
   int main(void)
   {
   printf("%d\n", ft_iterative_power(0, 5));
   printf("%d\n", ft_iterative_power(12, 1));
   printf("%d\n", ft_iterative_power(3, 0));
   return (0);
   }
   */
