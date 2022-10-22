/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:41:49 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/22 16:57:20 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] < '!' || str[c] > '~')
			return (0);
		c++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = " ";

	printf("%d", ft_str_is_printable(str));
}*/
