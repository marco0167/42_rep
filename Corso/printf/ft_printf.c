/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:10:12 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/03 19:30:35 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void	printString(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

void	toUpper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
}

void	revertString(char * str)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		i++;
	}
	i--;
	while (i > j)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i--;
		j++;
	}
}

char	*hexToString(unsigned long nbr, int upper)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 100);
	while (nbr > 0)
	{
		if (nbr % 16 < 10)
			str[i] = nbr % 16 + '0';
		else
			str[i] = nbr % 16 + 'a' - 10;
		nbr = nbr / 16;
		i++;
	}
	str[i] = '\0';
	revertString(str);
	if (upper == 1)
		toUpper(str);
	printString(str);
	free(str);
	return (str);
}

void	decToString(long nbr)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 100);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str[i] = '\0';
	revertString(str);
	printString(str);
	free(str);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	char chr;

	va_start(args, 5);
	while (*format)
	{
		if (*format == '%')
			{
				format++;
				if (*format == 's')
					printString(va_arg(args, char *));
				if (*format == 'c')
				{
					chr = va_arg(args, int);
					write(1, &chr, 1);
				}
				if (*format == 'd')
					decToString(va_arg(args, int));
				if (*format == 'i')
					decToString(va_arg(args, int));
				if (*format == 'u')
					decToString(va_arg(args, unsigned int));
				if (*format == 'p')
				{
					write(1, "0x", 2);
					hexToString(va_arg(args, unsigned long), 0);
				}
				if (*format == 'x')
					hexToString(va_arg(args, unsigned long), 0);
				if (*format == 'X')
					hexToString(va_arg(args, unsigned long), 1);
				if (*format == '%')
					write(1, "%", 1);
				format++;
			}
		if (*format == '\0')
			break;
		write(1, format, 1);
		format++;
	}
	return (0);
}

int main()
{
	char *str = "Hello World";
	ft_printf("Hello %s, this is a %s test %p p %X %u %i %d %c %%", str, "cool", &str, 123, 123, 123, 123, 'c');
	printf("\n");
	printf("Hello %s, this is a %s test %p p %X %u %i %d %c %%", str, "cool", &str, 123, 123, 123, 123, 'c');

	return (0);
}
