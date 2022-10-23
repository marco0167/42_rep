/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:18:14 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/22 17:27:42 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 'A' && str[c] <= 'Z')
			str[c] += 32;
		c++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	c;

	c = 0;
	str = ft_strlowcase(str);
	while (str[c] != '\0')
	{
		if (str[c] >= 'a' && str[c] <= 'z')
			if (!(str[c - 1] >= 'a' && str[c - 1] <= 'z'))
				if (!(str[c - 1] >= 'A' && str[c - 1] <= 'Z'))
					if (!(str[c - 1] >= '0' && str[c - 1] <= '9'))
							str[c] -= 32;
		c++;
	}
	return (str);	
}
/*
int	main(void)
{
	char	str[] = "salut, commWnt tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s", ft_strcapitalize(str));
}*/