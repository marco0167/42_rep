/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:08:32 by mcoppola          #+#    #+#             */
/*   Updated: 2023/08/03 17:34:22 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_wait_start(long long start)
{
	long long	current;

	while (ft_current_time() < start)
		usleep(100);
}

void	ft_printer(t_philo *philo, char *str)
{
	if (philo->table->dead)
		return ;
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d %s\n", ft_current_time() - philo->table->start,
		philo->id + 1, str);
	pthread_mutex_unlock(&philo->table->print);
}

void	ft_philo_act(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	ft_printer(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork_mutex);
	ft_printer(philo, "has taken a fork");
	pthread_mutex_lock(&philo->read_write);
	philo->last_meal = ft_current_time();
	ft_printer(philo, "is eating");
	philo->meals++;
	if (philo->table->num_meals == philo->meals)
	{
		philo->is_full = 1;
		pthread_mutex_lock(&philo->table->philos_eaten_mutex);
		philo->table->philos_eaten++;
		pthread_mutex_unlock(&philo->table->philos_eaten_mutex);
	}
	pthread_mutex_unlock(&philo->read_write);
	ft_sleep(philo->table->time_to_eat * 1);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	ft_printer(philo, "is sleeping");
	ft_sleep(philo->table->time_to_sleep * 1);
}

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_wait_start(philo->table->start);
	if (philo->table->num_philos == 1)
	{
		ft_printer(philo, "is thinking");
		ft_printer(philo, "has taken a fork");
		ft_sleep(philo->table->time_to_die);
		return (NULL);
	}
	if (!philo->id % 2 == 0)
		ft_sleep(10);
	while (!philo->table->dead)
	{
		ft_printer(philo, "is thinking");
		ft_philo_act(philo);
		if (philo->table->num_meals != -1 && philo->is_full)
			return (NULL);
	}
	return (NULL);
}

void	*ft_controller(void *arg)
{
	t_send	*send;
	int		i;

	send = (t_send *)arg;
	ft_wait_start(send->table->start);
	while (1)
	{
		i = -1;
		while (++i < send->table->num_philos)
		{
			if (ft_current_time() - send->philos[i].last_meal
				> send->table->time_to_die)
			{
				ft_printer(&send->philos[i], "died");
				send->table->dead = 1;
			}
			if (send->table->dead)
				break ;
		}
		if (send->table->dead || (send->table->num_meals != -1
				&& send->table->philos_eaten == send->table->num_philos))
		{
			return (NULL);
		}
	}
}
