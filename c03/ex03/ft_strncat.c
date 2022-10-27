/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:23:15 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 18:23:18 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	while (dest[i] != 0)
		i++;
	while (src[k] != 0 && k < nb)
	{
		dest[i] = src[k];
		k++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
int main(void)
{
	unsigned int nb = 2;
	char dest[] = "Hello";
	char src[] = "My_Man_Yoo";
	printf("%s\n", ft_strncat(dest, src, nb));

}
*/
