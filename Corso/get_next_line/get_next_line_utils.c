/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:14:06 by mcoppola          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/21 18:13:12 by mcoppola         ###   ########.fr       */
=======
/*   Updated: 2023/02/11 18:38:29 by mcoppola         ###   ########.fr       */
>>>>>>> 798c0ca0ffdc012def4fad4d98454c91376a1a5f
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		if (*(s + i) == (unsigned char)c)
		{
			return (1);
		}
		if (c != 0 && *(s + i) == 0)
		{
			return (0);
		}
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
<<<<<<< HEAD
	new_str = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
=======
	new_str = malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * sizeof(char));
>>>>>>> 798c0ca0ffdc012def4fad4d98454c91376a1a5f
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*set_static_str(char *line)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	i++;
	new_str = malloc((ft_strlen(line) - i + 1) * sizeof(char));
	while (line[i] != '\0')
	{
		new_str[j] = line[i];
		line[i] = '\0';
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
