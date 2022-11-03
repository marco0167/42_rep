/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:15:25 by mcoppola          #+#    #+#             */
/*   Updated: 2022/11/02 15:53:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_iterative_factorial(int nbr)
{
	int	c;

	c = nbr;
	if (nbr < 0)
		return (0);
	if (nbr == 0)
		return (1);
	while (c > 2)
	{
		c--;
		nbr *= c;
	}
	return (nbr);
}
/*
   int	main()
   {
   printf("%d\n", ft_iterative_factorial(124211442));
   }
   */
