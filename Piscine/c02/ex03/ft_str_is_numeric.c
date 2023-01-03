/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:41:49 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 12:41:54 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	v;

	i = 0;
	if (str[i] == 0)
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			v = 1;
		else
			return (0);
		i++;
	}
	return (v);
}
/*
int main(void)
{
	char string[] = "";
	printf("%d\n",ft_str_is_numeric(string));
}
*/
