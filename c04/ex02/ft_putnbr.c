/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:49 by mcoppola          #+#    #+#             */
/*   Updated: 2022/11/01 19:48:10 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer_int(long ml10, int counter, long nblong);

void	ft_putnbr(int nb)
{
	int		e;
	long	nbl;
	long	mlt;
	long	nbl2;

	e = 0;
	mlt = 1;
	nbl = nb;
	if (nbl < 0)
	{
		nbl *= -1;
		write(1, "-", 1);
	}
	nbl2 = nbl;
	while (nbl2 >= 1)
	{
		mlt *= 10;
		nbl2 /= 10;
		e++;
	}
	printer_int(mlt, e, nbl);
	if (nbl == 0)
		write(1, "0", 1);
}

void	printer_int(long ml10, int counter, long nblong)
{
	char	c;
	long	x;

	ml10 /= 10;
	while (counter > 0)
	{
		x = nblong;
		c = x / ml10 % 10 + '0';
		write(1, &c, 1);
		counter --;
		ml10 /= 10;
	}
}
/*
   int	main(void)
   {
   ft_putnbr(-1132);
   }
   */
