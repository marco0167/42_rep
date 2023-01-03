/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:41:22 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 12:41:26 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	v;

	i = 0;
	if (str[i] == 0)
		return (1);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			v = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
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
	printf("%d\n", ft_str_is_alpha(string));
}
*/
