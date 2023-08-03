/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:08:32 by mcoppola          #+#    #+#             */
/*   Updated: 2023/07/26 10:06:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_wait_start(long long start)
{
	long long	current;

	printf("OUT %lld---%lld\n", ft_current_time(), start);
	while ((current = ft_current_time()) < start)
	{
		usleep(100);
	}
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
	// philo->meals++;
	// if (philo->table->num_meals == philo->meals)
	// {
	// 	philo->is_full = 1;
	// 	pthread_mutex_lock(&philo->table->philos_eaten_mutex);
	// 	philo->table->philos_eaten++;
	// 	pthread_mutex_unlock(&philo->table->philos_eaten_mutex);
	// }
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
	printf("4\n");
	if (philo->id % 2 == 0)
		ft_sleep(900);
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
			pthread_mutex_lock(&send->philos[i].read_write);
			if (ft_current_time() - send->philos[i].last_meal > send->table->time_to_die)
			{
				printf("Philosopher %d died\n", send->philos[i].id);
				send->table->dead = 1;
			}
			pthread_mutex_unlock(&send->philos[i].read_write);
			if (send->table->dead)
				break ;
			i++;
		}
		printf("Checking philosopher death: dead=%d, philos_eaten=%d, num_philos=%d, num_meals=%d\n",
			send->table->dead, send->table->philos_eaten, send->table->num_philos, send->table->num_meals);
		if (send->table->dead || (send->table->num_meals != -1 && send->table->philos_eaten == send->table->num_philos))
		{
			printf("Controller thread exiting\n");
			return (NULL);
		}
		usleep(1000);
	}
}
