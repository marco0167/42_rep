/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:04 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/06 17:34:14 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	// if (c == '\0')
	// 	return ('\0');
	while (s[i] != c && s[i])
	{
		i++;
	}
	if (s[i] == c)
		return (s + i);
	return ("(null)");
}

int	main(void)
{
	char	*s;

	s = "ciaoo";
	// printf("%s\n", strchr(s, '5'));
	printf("%s\n", ft_strchr(s, '5'));
}
