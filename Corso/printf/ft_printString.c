/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printString.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:21:27 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/07 17:40:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	printString(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i])
	{
		temp = &str[i++];
		write(1, temp, 1);
	}
	return (i);
}
