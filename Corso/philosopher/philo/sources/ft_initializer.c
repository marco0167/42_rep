/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:49:17 by mcoppola          #+#    #+#             */
/*   Updated: 2023/08/03 18:10:53 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_init(t_philo *philo, int i, t_table *table)
{
	philo[i].id = i;
	philo[i].meals = 0;
	philo[i].left_fork = i;
	philo[i].right_fork = (i + 1) % table->num_philos;
	philo[i].left_fork_mutex = &table->forks[philo[i].left_fork];
	philo[i].right_fork_mutex = &table->forks[philo[i].right_fork];
	philo[i].table = table;
	philo[i].last_meal = table->start;
	pthread_mutex_init(&philo[i].read_write, NULL);
}

void	ft_philos_init(t_table *table, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < table->num_philos)
		ft_philo_init(philos, i, table);
}

int	ft_table_init(t_table *table, int ac, char **av)
{
	int	i;

	i = -1;
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->num_meals = ft_atoi(av[5]);
	else
		table->num_meals = -1;
	table->dead = 0;
	table->philos_eaten = 0;
	table->start = ft_current_time() + (table->num_philos * 2 * 10);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		return (1);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->philos_eaten_mutex, NULL);
	pthread_mutex_init(&table->controller_mutex, NULL);
	while (++i < table->num_philos)
		pthread_mutex_init(&table->forks[i], NULL);
	return (0);
}

int	ft_initializer(int ac, char **av, t_table *table, t_philo *philos)
{
	t_send	send;

	if (ft_table_init(table, ac, av))
		return (1);
	philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!philos)
		return (1);
	ft_philos_init(table, philos);
	ft_thread_starter(philos, table);
	send.philos = philos;
	send.table = table;
	ft_controller_start(&send);
	return (0);
}
