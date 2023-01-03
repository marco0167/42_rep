/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:11:38 by mcoppola          #+#    #+#             */
/*   Updated: 2022/11/02 15:52:29 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_recursive_factorial(int nbr)
{
	if (nbr < 0)
		return (0);
	if (nbr == 0)
		return (1);
	return (nbr * ft_recursive_factorial(nbr - 1));
}
/*
   int	main()
   {
   printf("%d\n", ft_recursive_factorial(7));
   }
   */
