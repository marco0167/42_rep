/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:04 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/25 23:38:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && c != *s)
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *) s);
	}
	return (0);
}
// int main()
// {
// 	char s[]="ciaoaoaoasssd";
// 	printf("%s\n", ft_strchr(s, 'r'));
// 	printf("%s\n", strchr(s, 'r'));
// }
