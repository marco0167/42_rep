/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:10:17 by mcoppola          #+#    #+#             */
/*   Updated: 2023/02/08 14:53:21 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_to_upper(char *str);
void	ft_revert_string(char *str);
int		ft_print_string(char *str);
int		ft_dec_to_string(long nbr);
int		ft_hex_to_string(unsigned long nbr, int upper);
int		ft_printf(const char *format, ...);
int		ft_printf_condition(const char *format, va_list args);
int		ft_printf_condition2(const char *format, va_list args);

#endif
