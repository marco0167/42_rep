/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:53:14 by mcoppola          #+#    #+#             */
/*   Updated: 2022/11/01 18:36:05 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_checker(char *base)
{
	int	c;

	c = 0;
	while (base[c])
	{
		c++;
	}
	return (c);
}

void	print_reverse(char *str)
{
	int	c;

	c = 0;
	while (str[c] != 0)
		c++;
	while (c > 0)
	{
		write(1, &str[c - 1], 1);
		c--;
	}
}

void	converter(int nbr, int ft_base, char *base)
{
	char	str[200];
	int		c;

	c = 0;
	while (nbr > 0)
	{
		str[c] = base[nbr % ft_base];
		nbr /= ft_base;
		c++;
	}
	str[c] = '\0';
	print_reverse(str);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	tp_base;

	tp_base = base_checker(base);
	converter(nbr, tp_base, base);
}
/*
int	main(void)
{
	ft_putnbr_base(123120, "01234567");
}
*/