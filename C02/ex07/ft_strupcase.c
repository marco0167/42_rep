/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:58:26 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/22 17:09:02 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 'a' && str[c] <= 'z')
			str[c] -= 32;
		c++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "ssdaASDa23sda";

	printf("%s", ft_strupcase(str));
}*/
