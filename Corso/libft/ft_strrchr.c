/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:42 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/28 16:36:45 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	last;
	int				found;

	found = 0;
	i = 0;
	last = 0;
	while (1)
	{
		if (*(s + i) == (unsigned char)c)
		{
			last = i;
			found = 1;
		}
		if (*(s + i) == 0)
		{
			break ;
		}
		i++;
	}
	if (!found)
		return (0);
	return ((char *)s + last);
}

// int main()
// {
// 	// void *d = 0;
// 	char s[]="ciaoaoaoasssd";

// 	printf("%s", ft_strrchr(s, '0'));
// 	printf("%s", strrchr(s, '0'));
// }
