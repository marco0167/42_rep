/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:10:12 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/15 11:25:56 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += ft_printf_condition(format, args);
			format++;
		}
		else
		{
			if (*format == '\0')
				break ;
			write(1, format++, 1);
			i++;
		}
	}
	va_end(args);
	return (i);
}

// int	main(void)
// {
// 	char	*str = "H";

// 	ft_printf("%d\n", ft_printf("ciao%c %s%c%c%c%c", 'a', 'i', 'u', 'e', 'o'));
// 	ft_printf("\n");
// 	ft_printf("%d\n", ft_printf("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o'));
// 	return (0);
// }
