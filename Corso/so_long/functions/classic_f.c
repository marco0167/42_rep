/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:29:15 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/20 18:36:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *char_src;
	char *char_dest;

	if (!dest && !src)
		return ((void *)0);
	char_src = (char *)src;
	char_dest = (char *)dest;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		// ft_printf("|char = %d-%c| ", char_dest[i], char_dest[i]);
		i++;
	}
	// ft_printf("\n");
	return (dest);
}

char *ft_strdup(const char *s1)
{
	size_t len_s1;
	char *s2;

	len_s1 = ft_strlen2((char *)s1);
	s2 = (char *)malloc(sizeof(char) * (len_s1));
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, (len_s1 + 1));
	return (s2);
}

int ft_strlen2(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
	{
		i--;
		s[i] = 0;
	}
	return (i);
}
