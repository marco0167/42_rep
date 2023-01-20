/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:04:58 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/18 20:01:07 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, int n)
{
	int			i;
	const char	*char_s;

	char_s = (const char *)s;
	i = 0;
	while (i < n && char_s[i])
	{
		if (char_s[i] == c)
			return (((void *)char_s) + i);
		i++;
	}
	return ((void *)0);
}
