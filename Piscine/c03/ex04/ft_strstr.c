/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:23:36 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 18:24:36 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (to_find[0] == 0)
		return (str = &str[0]);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = i;
			k = 0;
			while (str[j] == to_find[k] && to_find[k])
			{
				k++;
				j++;
				if (to_find[k] == 0)
					return (str = &str[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str[] = "Hello_World";
	char to_find[] = "World";
	printf("%s\n", ft_strstr(str, to_find));
}
*/
