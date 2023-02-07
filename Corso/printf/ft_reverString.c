/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverString.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:27:15 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/07 17:28:00 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	revertString(char * str)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		i++;
	}
	i--;
	while (i > j)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i--;
		j++;
	}
}
