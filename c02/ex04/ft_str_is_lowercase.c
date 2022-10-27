/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:42:08 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 12:42:12 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	v;

	i = 0;
	if (str[i] == 0)
		return (1);
	while (str[i] != 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
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
	char string[] = "hello world";
	printf("%d\n", ft_str_is_lowercase(string));	
}
*/
