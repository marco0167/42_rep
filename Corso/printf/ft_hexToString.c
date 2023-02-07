/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexToString.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:28:31 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/07 17:38:27 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexToString(unsigned long nbr, int upper)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * 100);
	while (nbr > 0)
	{
		if (nbr % 16 < 10)
			str[i] = nbr % 16 + '0';
		else
			str[i] = nbr % 16 + 'a' - 10;
		nbr = nbr / 16;
		i++;
	}
	str[i] = '\0';
	revertString(str);
	if (upper == 1)
		toUpper(str);
	j = printString(str);
	free(str);
	return (j);
}
