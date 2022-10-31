/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:01:57 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 21:14:39 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	c;
	int	nb;
	int	sign;
	int	num_found;

	c = 0;
	nb = 0;
	sign = 1;
	num_found = 0;
	while (str[c] != 0)
	{
		if (num_found == 1 && !(str[c] >= '0' && str[c] <= '9'))
			break;
		else if(str[c] >= '0' && str[c] <= '9')
		{
			nb *= 10;
			nb += str[c] - '0';
			num_found = 1;
		}
		else if (str[c] == '-') 
			sign *= -1;
		c++;
	}
		return (nb * sign);
}

int	main(void)
{
	printf("%d", ft_atoi("   ---+---+1234ab567"));
}
