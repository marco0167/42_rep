/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:42 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/25 23:37:22 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int			j;
	const char	*begin;

	begin = s;
	j = ft_strlen((char *)s);
	s = (s + j);
	while (*s != *begin && c != *s)
		s--;
	if (c == *s)
		return ((char *) s);
	return (0);
}

// int main()
// {
// 	// void *d = 0;
// 	char s[]="ciaoaoaoasssd";

// 	printf("%s", ft_strrchr(s, '0'));
// 	printf("%s", strrchr(s, '0'));
// }
