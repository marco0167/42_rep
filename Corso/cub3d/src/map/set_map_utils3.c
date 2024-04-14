/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:34 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:26:35 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_numeric(char *str)
{
	int	hasdigits;

	hasdigits = 0;
	while (*str)
	{
		if (is_space((unsigned char)*str))
		{
			str++;
			continue ;
		}
		else if (*str == '-' || *str == '+')
		{
			if (hasdigits)
				return (0);
		}
		else if (!is_digit((unsigned char)*str))
			return (0);
		else
			hasdigits = 1;
		str++;
	}
	return (hasdigits);
}

int	check_numbers(const char *str)
{
	int	count;
	int	in_number;

	count = 0;
	in_number = 0;
	while (*str)
	{
		if (is_digit((unsigned char)*str))
		{
			if (!in_number)
			{
				in_number = 1;
				count++;
			}
		}
		else if (is_space((unsigned char)*str))
			in_number = 0;
		else
			return (-1);
		str++;
	}
	if (count > 1)
		return (-1);
	return (0);
}

/**
 * Split the string into an int array
 *
 * @param string: the string to split
 * @param divider: the "divider" character
 * @return an array of int
*/
int	check_is_empty(char **matrix, int i)
{
	int	k;

	k = 0;
	if (i != 3)
		return (0);
	if (!*matrix[0] || !*matrix[1] || !*matrix[2])
		return (0);
	return (1);
}

int	check_dbl_comma(char *s, char c)
{
	int	j;

	j = 0;
	while (s[j++])
	{
		if (s[j] == c && s[j + 1] == c)
			return (0);
	}
	return (1);
}
