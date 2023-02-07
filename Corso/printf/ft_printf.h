/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:10:17 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/07 17:38:41 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

void	toUpper(char *str);
void	revertString(char * str);
int		printString(char *str);
int		decToString(long nbr);
int		hexToString(unsigned long nbr, int upper);
int		ft_printf(const char *format, ...);

#endif
