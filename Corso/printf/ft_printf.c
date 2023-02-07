/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:10:12 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/07 18:09:56 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// # include <unistd.h>
// # include <stdlib.h>
// # include <stdarg.h>
// # include <stdio.h>

// void	toUpper(char *str)
// {
// 	while (*str)
// 	{
// 		if (*str >= 'a' && *str <= 'z')
// 			*str = *str - 32;
// 		str++;
// 	}
// }
// void	revertString(char * str)
// {
// 	char	temp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	i--;
// 	while (i > j)
// 	{
// 		temp = str[j];
// 		str[j] = str[i];
// 		str[i] = temp;
// 		i--;
// 		j++;
// 	}
// }
// int	decToString(long nbr)
// {
// 	char *str;
// 	int i;

// 	i = 0;
// 	str = (char *)malloc(sizeof(char) * 100);
// 	if (nbr < 0)
// 	{
// 		write(1, "-", 1);
// 		nbr = nbr * -1;
// 	}
// 	while (nbr > 0)
// 	{
// 		str[i] = nbr % 10 + '0';
// 		nbr = nbr / 10;
// 		i++;
// 	}
// 	str[i] = '\0';
// 	revertString(str);
// 	i = printString(str);
// 	free(str);
// 	return (i);
// }

// int	hexToString(unsigned long nbr, int upper)
// {
// 	char *str;
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc(sizeof(char) * 100);
// 	while (nbr > 0)
// 	{
// 		if (nbr % 16 < 10)
// 			str[i] = nbr % 16 + '0';
// 		else
// 			str[i] = nbr % 16 + 'a' - 10;
// 		nbr = nbr / 16;
// 		i++;
// 	}
// 	str[i] = '\0';
// 	revertString(str);
// 	if (upper == 1)
// 		toUpper(str);
// 	j = printString(str);
// 	free(str);
// 	return (j);
// }

// int	printString(char *str)
// {
// 	int		i;
// 	char	*temp;

// 	i = 0;
// 	while (str[i])
// 	{
// 		temp = &str[i++];
// 		write(1, temp, 1);
// 	}
// 	return (i);
// }

int ft_printf(const char *format, ...)
{
	va_list args;
	char chr;
	unsigned int i;

	va_start(args, 5);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i++;
			if (*format == 's')
				i += printString(va_arg(args, char *));
			if (*format == 'c')
			{
				chr = va_arg(args, int);
				write(1, &chr, 1);
				i++;
			}
			if (*format == 'd')
				i += decToString(va_arg(args, int));
			if (*format == 'i')
				i += decToString(va_arg(args, int));
			if (*format == 'u')
				i += decToString(va_arg(args, unsigned int));
			if (*format == 'p')
			{
				write(1, "0x", 2);
				i += 2 + hexToString(va_arg(args, unsigned long), 0);
			}
			if (*format == 'x')
				i += hexToString(va_arg(args, unsigned long), 0);
			if (*format == 'X')
				i += hexToString(va_arg(args, unsigned long), 1);
			if (*format == '%')
			{
				write(1, "%", 1);
				i++;
			}
			format++;
		}
		else if(*format != '\0')
			i++;
		if (*format == '\0')
			break;
		write(1, format, 1);
		format++;
	}
	return (i);
}

int main()
{
	char *str = "H";

	printf("%d\n", ft_printf("H , a %s t %p p %X %u %i %d %c",  "cool", &str, 123, 123, 123, 123, 'c'));
	printf("\n");
	printf("%d\n", printf("H , a %s t %p p %X %u %i %d %c ",  "cool", &str, 123, 123, 123, 123, 'c'));

	return (0);
}
