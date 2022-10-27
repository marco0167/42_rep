/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:46:07 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/27 12:46:21 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	ft_strlowcase(str);
	i = 0;
	flag = 1;
	while (str[i] != 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z' && flag == 1)
		{
			str[i] -= 32;
			flag = 0;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z'))
			flag = 0;
		else if (str[i] >= '0' && str[i] <= '9')
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (str);
}
/*
int main(void)
{
	char string[] = " 012 213 123 123 Sdasdl qw dD  D a sS sS Ss";
	printf("%s - String Before \n", string);
	ft_strcapitalize(string);
	printf("%s - String After \n", string);
}
*/
