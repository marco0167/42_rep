/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:14:18 by mcoppola          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/21 18:13:53 by mcoppola         ###   ########.fr       */
=======
/*   Updated: 2023/02/11 18:42:06 by mcoppola         ###   ########.fr       */
>>>>>>> 798c0ca0ffdc012def4fad4d98454c91376a1a5f
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*set_static_str(char *line);
char	*get_next_line(int fd);

#endif
