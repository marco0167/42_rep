/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:11:31 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/17 12:17:08 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
void	*ft_memset(void *b, int c, size_t len)
{
	int	i;
	
	i = 0;
	while (i < len)
	{
		b[i] = c;
		i++;
	}
}

int	main(void)
{
	char	*s;

	s = "ciaooooooee";
	memset(s, 'i',  5);
	printf("%s\n", s);
}
