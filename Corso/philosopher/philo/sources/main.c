/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:14:07 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/11 20:44:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table	*table;
	t_send	*send;

	ft_validity_checker(ac, av);
	table = malloc(sizeof(t_table));
	send = malloc(sizeof(t_send));
	table->ph_n = ft_atoi(av[1]);
	table->t_die = ft_atoi(av[2]);
	table->t_eat = ft_atoi(av[3]);
	table->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->meals_n = ft_atoi(av[5]);
	else
		table->meals_n = -1;
	send->table = table;
	init(send);
	ft_close(send);
}
