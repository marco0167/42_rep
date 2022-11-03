/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:55:09 by mcoppola          #+#    #+#             */
/*   Updated: 2022/11/03 11:24:35 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_sqrt(int nb)
{
	long	index;
	long	b;

	b = nb;
	if (b <= 0)
		return (0);
	if (b == 1)
		return (1);
	index = 2;
	if (b >= 2)
	{
		while (index * index <= b)
		{
			if (index * index == b)
				return (index);
			index++;
		}
	}
	return (0);
}
/*
   int main(void)
   {
   printf("%d\n",ft_sqrt(-300));
   }
   */
