/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:49:32 by mcoppola          #+#    #+#             */
/*   Updated: 2022/10/20 17:44:07 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	c;

	c = 0;
	while (src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	str[] = "ciaoo";
	char	dest_str[] = "     ";
	
	printf("%s",ft_strcpy(dest_str, str));
	
}
*/
