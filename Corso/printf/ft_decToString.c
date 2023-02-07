/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decToString.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:29:20 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/07 17:36:32 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decToString(long nbr)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 100);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str[i] = '\0';
	revertString(str);
	i = printString(str);
	free(str);
	return (i);
}
