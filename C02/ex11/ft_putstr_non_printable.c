/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:46:53 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/23 17:01:33 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	dec_to_hex(char c)
{
	int	dec;

	dec = c;
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[dec / 16]);
	ft_putchar("0123456789abcdef"[dec % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	c;
	char	*sbl;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] == '\\')
		{
			sbl = &str[c];
			write(1, (sbl), 2);
			c++;
		}
		if (str[c] >= 33 && str[c] <= 126)
			ft_putchar(str[c]);
		c++;
	}
}
/*
int	main(void)
{
	char	*str = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
}*/
