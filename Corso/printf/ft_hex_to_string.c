/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:28:31 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/08 16:19:16 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_to_string(unsigned long nbr, int upper)
{
	char	*str;
	int		i;
	int		j;

	if (nbr == 0)
		return (write(1, "0", 1));
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
	ft_revert_string(str);
	if (upper == 1)
		ft_to_upper(str);
	j = ft_print_string(str);
	free(str);
	return (j);
}
