/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 07:49:44 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/14 09:01:31 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	dec;

	dec = 'a';
	while (dec < 123)
	{
		write(1, &dec, 1);
		dec++;
	}
}
