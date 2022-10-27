/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:44:01 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 12:44:10 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (str);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
int main(void)
{
	char string[] = "HELLO";
	printf("%s\n", ft_strlowcase(string));
}
*/
