/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:54:29 by mcoppola          #+#    #+#             */
/*   Updated: 2023/01/06 16:42:41 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(char *s, int n)
{
	while (n > 0)
	{
		s[n - 1] = '\0';
		n--;
	}
}
