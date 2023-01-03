/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:50:33 by mcoppola          #+#    #+#             */
/*   Updated: 2022/11/03 13:37:19 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power > 1)
		return (nb * ft_recursive_power(nb, (power - 1)));
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (result);
}
/*
   int main(void)
   {
   printf("%d\n", ft_recursive_power(3, 5));
   printf("%d\n", ft_recursive_power(12, 1));
   printf("%d\n", ft_recursive_power(3, 0));
   return (0);
   }
   */
