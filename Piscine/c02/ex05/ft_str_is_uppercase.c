/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:42:35 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 12:42:45 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	v;

	i = 0;
	if (str[i] == 0)
		return (1);
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			v = 1;
		else
			return (0);
		i++;
	}
	return (v);
}
/*
int	main(void)
{
	char string[] = "HELLO";
	printf("%d\n", ft_str_is_uppercase(string));	
}
*/
