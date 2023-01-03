/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:22:50 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 18:22:53 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		ls;

	i = 0;
	ls = 0;
	while (dest[i] != 0)
		i++;
	while (src[ls] != 0)
	{
		dest[i] = src[ls];
		ls++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
int	main(void)
{
	char string1[21] = "Yo  ";
	char string2[] = "Hello New World";
	printf("%s\n", ft_strcat(string1, string2));
}
*/
