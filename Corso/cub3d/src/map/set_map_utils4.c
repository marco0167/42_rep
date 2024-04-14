/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:38 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/10 23:26:39 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	*convert_to_int_arr(char **matrix, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	i = 0;
	while (matrix[i])
	{
		if (is_numeric(matrix[i]) && !check_numbers(matrix[i]))
		{
			arr[i] = ft_atoi(matrix[i]);
			if (arr[i] < 0 || arr[i] > 255)
				return (free(arr), NULL);
		}
		else
		{
			free(arr);
			return (NULL);
		}
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (arr);
}

int	*string_to_num_arr(char *string, char divider)
{
	char	**matrix;
	int		size;

	if (!check_dbl_comma(string, divider))
		return (NULL);
	matrix = ft_split(string, divider);
	size = 0;
	while (matrix[size])
		size++;
	if (!check_is_empty(matrix, size))
		return (NULL);
	return (convert_to_int_arr(matrix, size));
}
