/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_condition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:11:42 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/08 16:42:18 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_condition2(const char *format, va_list args)
{
	int		i;

	i = 0;
	if (*format == 's')
		i += ft_print_string(va_arg(args, char *));
	if (*format == 'd')
		i += ft_dec_to_string(va_arg(args, int));
	if (*format == 'x')
		i += ft_hex_to_string(va_arg(args, unsigned int), 0);
	if (*format == 'X')
		i += ft_hex_to_string(va_arg(args, unsigned int), 1);
	if (*format == '%')
	{
		write(1, "%", 1);
		i++;
	}
	return (i);
}

int	ft_printf_condition(const char *format, va_list args)
{
	int		i;
	char	chr;

	i = 0;
	if (*format == 'c')
	{
		chr = va_arg(args, int);
		write(1, &chr, 1);
		i++;
	}
	if (*format == 'i')
		i += ft_dec_to_string(va_arg(args, int));
	if (*format == 'u')
		i += ft_dec_to_string(va_arg(args, unsigned int));
	if (*format == 'p')
	{
		i += write(1, "0x", 2);
		i += ft_hex_to_string(va_arg(args, unsigned long), 0);
	}
	i += ft_printf_condition2(format, args);
	return (i);
}
