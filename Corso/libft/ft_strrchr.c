/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:42 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/20 15:29:29 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s) - 1;
	if(!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (((char *)s) + i);
		i--;
	}
	if (s[i] == c)
		return (((char *)s) + i);
	return (NULL);
}

// int main()
// {
// 	// void *d = 0;
// 	char s[]="ciaoaoaoasssd";

// 	printf("%s", ft_strrchr(s, '0'));
// 	printf("%s", strrchr(s, '0'));
// }
