/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:21:50 by mcoppola          #+#    #+#             */
/*   Updated: 2022/11/03 11:27:30 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_is_prime(int nb)
{
	int	max;
	int	c;
	int	divider;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb < 0)
		return (0);
	divider = 0;
	c = 2;
	max = nb / 2 + 1;
	while (c <= max)
	{
		if (nb % c == 0)
			divider++;
		c++;
	}
	if (divider == 0)
		return (1);
	return (0);
}

   int main(void)
   {
   printf("%d\n", ft_is_prime(-100));
   }
   
