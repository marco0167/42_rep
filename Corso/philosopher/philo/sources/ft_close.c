/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:07:14 by mcoppola          #+#    #+#             */
/*   Updated: 2023/07/25 16:32:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_close(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(philos[i].read_write);
		pthread_mutex_destroy(&table->forks[i]);
		free(philos[i].read_write);
		i++;
	}
	pthread_mutex_destroy(table->print);
	pthread_mutex_destroy(table->philos_eaten_mutex);
	free(table->forks);
	free(table->print);
	free(table->philos_eaten_mutex);
	free(philos);
	free(table);
}
