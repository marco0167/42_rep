/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:08:32 by mcoppola          #+#    #+#             */
/*   Updated: 2023/07/25 16:58:00 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_wait_start(long long start)
{
	while (ft_current_time() < start)
		usleep(100);
}

void	ft_printer(t_philo *philo, char *str)
{
	if (philo->table->dead)
		return ;
	pthread_mutex_lock(philo->table->print);
	printf("q0\n");
	printf("%lld %d %s\n", ft_current_time() - philo->table->start,
		philo->id + 1, str);
	pthread_mutex_unlock(philo->table->print);
}

void	ft_philo_act(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	ft_printer(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork_mutex);
	ft_printer(philo, "has taken a fork");
	pthread_mutex_lock(philo->read_write);
	philo->last_meal = ft_current_time();
	ft_printer(philo, "is eating");
	philo->meals++;
	if (philo->table->num_meals == philo->meals)
	{
		philo->is_full = 1;
		pthread_mutex_lock(philo->table->philos_eaten_mutex);
		philo->table->philos_eaten++;
		pthread_mutex_unlock(philo->table->philos_eaten_mutex);
	}
	pthread_mutex_unlock(philo->read_write);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	ft_printer(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_wait_start(philo->table->start);
	if (philo->id % 2 == 0)
		usleep(900);
	while (!philo->table->dead)
	{
	printf("0\n");
		ft_printer(philo, "is thinking");
	printf("1\n");
		ft_philo_act(philo);
	printf("2\n");
		if (philo->table->num_meals != -1 && philo->is_full)
			return (NULL);
	}
}

void	*ft_controller(void *arg)
{
	t_send	*send;
	int		i;

	send = (t_send *)arg;
	while (1)
	{
		i = 0;
		while (i < send->table->num_philos)
		{
			if (send->table->dead)
				return (NULL);
			if (send->table->num_meals == send->table->philos_eaten)
				return (NULL);
			pthread_mutex_lock(send->philos[i].read_write);
			if (ft_current_time() - send->philos[i].last_meal
				> send->table->time_to_die)
			{
				ft_printer(&send->philos[i], "died");
				send->table->dead = 1;
			}
			pthread_mutex_unlock(send->philos[i].read_write);
			i++;
		}
		usleep(1000);
	}
}
