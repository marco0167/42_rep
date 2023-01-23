/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:44:31 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/23 11:56:19 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len != 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}

//int	main()
//{
//	int	bf1[] = {1,2,3,4,5,6,7,8,9,10, '\0'};
//	int	bf2[] = {1,2,3,4,5,6,7,8,9,10, '\0'};
//	int i;
//
//	i = 0;
//	memmove(bf1 + 2, bf1, sizeof(int) * 8);
//	ft_memmove(bf2 + 2, bf2, sizeof(int) * 8);
//	while (bf1[i])
//	{
//		printf("i=%d, num=%d, indirizzo=%p\n", i, bf1[i], &bf1[i]);
//		i++;
//	}
//	i = 0;
//	while (bf2[i])
//	{
//		printf("i=%d, num=%d\n", i, bf2[i]);
//		i++;
//	}
//}
