/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:25:58 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/22 16:36:33 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] < 'A' || str[c] > 'Z')
			return (0);
		c++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "AasaA";

	printf("%d",ft_str_is_uppercase(str));
}*/
