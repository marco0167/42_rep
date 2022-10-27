/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:40:56 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 12:41:01 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (src[c] != 0 && c < n)
	{
		dest[c] = src[c];
		c++;
	}
	while (c < n)
	{
		dest[c] = 0;
		c++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src1[] = "Hello";
	char dest2[] = "New World is amazing";
	unsigned int nn = 20;

	printf("%s",ft_strncpy(dest2, src1, nn));
}
*/
