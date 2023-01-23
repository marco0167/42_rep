/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:58:28 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/23 19:48:13 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	n;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (srclen < dstsize - 1)
		n = srclen;
	else
		n = dstsize - 1;
	ft_memcpy(dst, src, n);
	dst[n] = '\0';
	return (srclen);
}
