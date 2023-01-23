/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:04 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/23 12:00:56 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return ((char *)ft_memchr(s, c, ft_strlen((char *)s)));
}
// int main()
// {
// 	char s[]="ciaoaoaoasssd";
// 	printf("%s\n", ft_strchr(s, 'r'));
// 	printf("%s\n", strchr(s, 'r'));
// }
