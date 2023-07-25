/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:49:17 by mcoppola          #+#    #+#             */
/*   Updated: 2023/07/25 16:56:26 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_init(t_philo *philo, int id, t_table *table)
{
	pthread_t	thread;

	philo->thread = thread;
	philo->id = id;
	philo->meals = 0;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % table->num_philos;
	philo->left_fork_mutex = &table->forks[philo->left_fork];
	philo->right_fork_mutex = &table->forks[philo->right_fork];
	philo->table = table;
	philo->last_meal = table->start;
	philo->read_write = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->read_write, NULL);
}

void	ft_philos_init(t_table *table, t_philo **philos)
{
	int		i;

	*philos = malloc(sizeof(t_philo) * table->num_philos);
	i = 0;
	while (i < table->num_philos)
	{
		ft_philo_init(philos[i], i, table);
		i++;
	}
}

void	ft_table_init(t_table **table, int ac, char **av)
{
	*table = malloc(sizeof(t_table));
	(*table)->dead = ft_atoi(av[1]);
	(*table)->num_philos = ft_atoi(av[1]);
	(*table)->time_to_die = ft_atoi(av[2]);
	(*table)->time_to_eat = ft_atoi(av[3]);
	(*table)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*table)->num_meals = ft_atoi(av[5]);
	else
		(*table)->num_meals = -1;
	(*table)->philos_eaten = 0;
	(*table)->forks = malloc(sizeof(pthread_mutex_t) * (*table)->num_philos);
	(*table)->print = malloc(sizeof(pthread_mutex_t));
	(*table)->philos_eaten_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*table)->print, NULL);
	pthread_mutex_init((*table)->philos_eaten_mutex, NULL);
}

void	ft_initializer(int ac, char **av, t_table *table, t_philo *philos)
{
	t_send	send;

	ft_table_init(&table, ac, av);
	ft_philos_init(table, &philos);
	ft_thread_starter(philos, table);
	send.philos = philos;
	send.table = table;
	ft_controller_start(&send);
}
