/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:25:49 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:25:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_atoi(const char *str)
{
	int			n;
	int			sign;
	const char	*s;

	n = 0;
	sign = 1;
	s = str;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r'
		|| *s == '\f' || *s == '\v')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10;
		n += *s - '0';
		s++;
	}
	return (n * sign);
}
