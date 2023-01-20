/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:09:22 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/20 14:54:59 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// potrebbe non dover fare il controllo ((char *)s)[i] all'interno del while
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((char *)s)[i])
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
