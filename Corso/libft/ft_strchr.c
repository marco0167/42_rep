/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:04 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/28 16:26:25 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		if (*(s + i) == (unsigned char)c)
		{
			return ((char *)s + i);
		}
		if (c != 0 && *(s + i) == 0)
		{
			return (0);
		}
		i++;
	}
}
// int main()
// {
// 	char s[]="ciaoaoaoasssd";
// 	printf("%s\n", ft_strchr(s, 'r'));
// 	printf("%s\n", strchr(s, 'r'));
// }
