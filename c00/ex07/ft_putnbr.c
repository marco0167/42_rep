/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:34:31 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/17 19:15:33 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	long_nb;
	long	app_nb;
	long	sec_nb;

	long_nb = nb;
	if (long_nb < 0)
	{
		write(1, "-", 1);
		long_nb = long_nb * -1;
	}
	while (long_nb > 0)
	{
		app_nb = long_nb % 10;
		long_nb = long_nb / 10;
		sec_nb = sec_nb * 10 + app_nb;
	}
	while (sec_nb > 0)
	{
		app_nb = sec_nb % 10 + '0';
		sec_nb = sec_nb / 10;
		write(1, &app_nb, 1);
	}
}
