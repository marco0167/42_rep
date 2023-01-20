/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:47:36 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/20 14:58:26 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	return (ft_memcmp(s1, s2, n));
}

// int	main()
// {
// 	char	s1[]= "";
// 	char	s2[]= "ciauoo";

// 	printf("%d\n", ft_strncmp(s1, s2, 4));
// 	printf("%d\n", strncmp(s1, s2, 4));
// }
