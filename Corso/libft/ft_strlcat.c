/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:53:13 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/23 19:59:51 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	n;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (dstlen + srclen);
	if (srclen < dstsize - dstlen - 1)
		n = srclen;
	else
		n = dstsize - dstlen - 1;
	ft_memcpy(dst + dstlen, src, n);
	dst[dstlen + n] = '\0';
	return (dstlen + srclen);
}
