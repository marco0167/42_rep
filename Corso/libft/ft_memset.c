/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:09:22 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/18 17:54:32 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// potrebbe non dover fare il controllo ((char *)s)[i] all'interno del while
void	*ft_memset(void *s, int c, int n)
{
	int	i;

	i = 0;
	while (i < n && ((char *)s)[i])
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
