/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:29:20 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/08 16:36:31 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_to_string(long nbr)
{
	char	*str;
	int		i;
	short	neg;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	neg = 0;
	str = (char *)malloc(sizeof(char) * 100);
	if (nbr < 0)
	{
		neg = write(1, "-", 1);
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str[i] = '\0';
	ft_revert_string(str);
	i = ft_print_string(str);
	free(str);
	return (i + neg);
}
