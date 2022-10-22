/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:47:29 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/20 19:39:44 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (src[c] != '\0' && c < n)
	{
		dest[c] = src[c];
		c++;
	}
	if (c <= n)
	{
		while (c <= n)
		{
			if (c != (n - 1))
				dest[c] = '\0';
			c++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	str1[] = "1234567";
	char	str2[7];

	printf("%s", ft_strncpy(str2, str1, 7));
}
*/
