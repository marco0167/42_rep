/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:14:07 by mcoppola          #+#    #+#             */
/*   Updated: 2023/07/25 14:31:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philos;

	if (!ft_validity_checker(ac, av))
		return (1);
	ft_initializer(ac, av, table, philos);
	return (0);
}
