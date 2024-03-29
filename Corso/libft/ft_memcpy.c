/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:14:33 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/26 00:15:28 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* potrebbe non dover fare i controlli char_src[i] && char_dest[i]
all'interno del while
P.S. non li doveva fare...*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_src;
	char	*char_dest;

	if (!dest && !src)
		return ((void *)0);
	char_src = (char *)src;
	char_dest = (char *)dest;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
