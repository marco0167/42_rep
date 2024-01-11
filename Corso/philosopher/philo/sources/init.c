/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:09:53 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/11 21:05:11 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_table(t_send *send)
{
	int	i;

	send->table->forks = malloc(sizeof(pthread_mutex_t) * send->table->ph_n);
	i = 0;
	while (i < send->table->ph_n)
		pthread_mutex_init(&send->table->forks[i++], NULL);
}

t_philo	*init_philo(t_send *send, int index)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->dead = 0;
	philo->t_eaten = 0;
	philo->last_meal = 0;
	philo->id = index;
	philo->left_fork = &send->table->forks[index];
	if (index + 1 == send->table->ph_n)
		philo->right_fork = &send->table->forks[0];
	else
		philo->right_fork = &send->table->forks[index + 1];
	return (philo);
}

void	init_philos(t_send *send)
{
	int	i;

	send->philos = malloc(sizeof(t_philo) * send->table->ph_n);
	i = 0;
	while (i < send->table->ph_n)
	{
		send->philos[i] = init_philo(send, i);
		i++;
	}
}

void	init(t_send *send)
{
	init_table(send);
	init_philos(send);
	int i;

	i = 0;
	while (i < send->table->ph_n)
	{
		pthread_create(&send->philos[i]->tread, NULL, &routine, send->philos[i]);
		i++;
	}
	i = 0;
	while (i < send->table->ph_n)
	{
		pthread_join(send->philos[i]->tread, NULL);
		i++;
	}
}
