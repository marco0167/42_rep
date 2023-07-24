/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:14:07 by mcoppola          #+#    #+#             */
/*   Updated: 2023/07/21 13:48:36 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	if (!ft_validity_checker(ac, av))
		return (1);
	ft_initializer(ac, av);
	return (0);
}
