/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:11:57 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/20 19:39:03 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (!(str[c] >= 'A' && str[c] <= 'Z'))
			if (!(str[c] >= 'a' && str[c] <= 'z'))
				return (0);
		c++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "3";

	printf("%d", ft_str_is_alpha(str));
}
*/
