/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:44:31 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/22 21:03:12 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main()
{
	int	bf1[10] = {1,2,3,4,5,6,7,8,9,10};
	// int	bf2[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;

	i = 0;
	memmove(bf1 + 2, bf1, sizeof(int) * 10);
	// memcpy(bf2 + 2, bf1, sizeof(int) * 10);
	while (bf1[i])
	{
		printf("i=%d, num=%d, indirizzo=%p\n", i, bf1[i], &bf1[i]);
		i++;
	}
	i = 0;
	// while (bf2[i])
	// {
	// 	printf("i=%d, num=%d\n", i, bf2[i]);
	// 	i++;
	// }

}
