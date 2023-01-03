/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:46:53 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/25 23:43:42 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 32 && str[c] <= 126)
			ft_putchar(str[c]);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str[c] / 16]);
			ft_putchar("0123456789abcdef"[str[c] % 16]);
		}
		c++;
	}
}
/*
int	main(void)
{
	char	*str = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
}
*/
