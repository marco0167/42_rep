/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:53:15 by mcoppola          #+#    #+#             */
/*   Updated: 2023/08/03 17:05:18 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_thread_starter(t_philo *philos, t_table *table)
{
	int	i;

	table->start = ft_current_time() +(table->num_philos * 20);
	i = 0;
	while (i < table->num_philos)
	{
		pthread_create(&philos[i].thread, NULL, &ft_philo_routine, &philos[i]);
		i++;
	}
}

void	ft_controller_start(t_send *send)
{
	pthread_t	controller;
	int			i;

	pthread_create(&controller, NULL, &ft_controller, send);
	i = 0;
	while (i < send->table->num_philos)
	{
		pthread_join(send->philos[i].thread, NULL);
		i++;
	}
	pthread_join(controller, NULL);
}
