/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:19:05 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/21 18:19:23 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	int			byte;
	static char	*static_str;

	line = "";
	if (static_str != NULL)
	{
		line = static_str;
	}
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (ft_strchr(line, '\n') != 1 && byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		line = ft_strjoin(line, buf);
	}
	free(buf);
	if (byte < 1)
		return (NULL);
	static_str = set_static_str(line);
	return (line);
}

<<<<<<< HEAD
// int    main(void)
// {
//     int        fd;

//     fd = open("test", O_RDONLY);
//     printf("line: %s", get_next_line(fd));
//     printf("line: %s", get_next_line(fd));
//     printf("line: %s", get_next_line(fd));
//     printf("line: %s", get_next_line(fd));
//     printf("line: %s", get_next_line(fd));
//     printf("line: %s", get_next_line(fd));
//     printf("line: %s", get_next_line(fd));
//     return (0);
=======
// int	main(void)
// {
// 	int		fd;

// 	fd = open("test", O_RDONLY);
// 	printf("line: %s", get_next_line(fd));
// 	printf("line: %s", get_next_line(fd));
// 	printf("line: %s", get_next_line(fd));
// 	printf("line: %s", get_next_line(fd));
// 	printf("line: %s", get_next_line(fd));
// 	printf("line: %s", get_next_line(fd));
// 	printf("line: %s", get_next_line(fd));
// 	return (0);
>>>>>>> 798c0ca0ffdc012def4fad4d98454c91376a1a5f
// }
