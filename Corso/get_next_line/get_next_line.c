/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:14:10 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/03 14:59:11 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// int BUFFER_SIZE= 10;
size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}


char	*ft_strjoin(char const *s1, char const *s2, char *static_str)
{
	char	*new_str;
	int		i;
	int		j;
	size_t	s2_len;
	size_t	static_str_len;

	s2_len = ft_strlen((char *)s2);
	if (ft_strlen(static_str) > 0)
		static_str_len = ft_strlen(static_str);
	else
		static_str_len = 0;
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc((ft_strlen((char *)s1)
				+ s2_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1[j] != '\n')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = s2[j];
	//fai un ciclo dove riempri la funzione statica con la parte del buffer dopo lo \n
	if (s2[j] != '\0')
	{
		static_str = malloc((static_str_len + s2_len - j) * sizeof(char));
		j++;
		i = static_str_len;
		while (s2[j] != '\0')
		{
			static_str[i] = s2[j];
			i++;
			j++;
		}
		static_str[i] = s2[j];
		// printf("static_str: %s", static_str);
	}
	return (new_str);
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

char	*get_next_line(int fd)
{
	char		*buf;
	char		*str;
	static char	*static_str;
	size_t		byte;
	size_t		final_byte;
	int			i;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (ft_strlen(static_str) > 0)
		str = static_str;
	else
		str = "";
	while (ft_strchr(str, '\n') != 1)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		str = ft_strjoin(str, buf, static_str);
	}
	final_byte = ft_strlen(str);


	printf("|linea| %s", str);
	return ("");
}


int main()
{
	int fd = open("test", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
}

