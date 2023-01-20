/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:14:33 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/18 17:55:23 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* potrebbe non dover fare i controlli char_src[i] && char_dest[i]
all'interno del while */
void	*ft_memcpy(void *dest, void *src, int n)
{
	int		i;
	char	*char_src;
	char	*char_dest;

	if (dest == (void *)0)
		return ((void *)0);
	char_src = (char *)src;
	char_dest = (char *)dest;
	i = 0;
	while (i < n && char_src[i] && char_dest[i])
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
