/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:04:58 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/20 15:32:48 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*char_s;

	char_s = (const char *)s;
	i = 0;
	while (i < n && char_s[i])
	{
		if (char_s[i] == (unsigned char)c)
			return (((void *)char_s) + i);
		i++;
	}
	if (((char *)char_s)[i] == (unsigned char)c)
		return (((void *)char_s) + i);
	return (NULL);
}