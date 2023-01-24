/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:53:26 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/24 18:53:38 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*s2;

	len_s1 = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, (len_s1 + 1));
	return (s2);
}
