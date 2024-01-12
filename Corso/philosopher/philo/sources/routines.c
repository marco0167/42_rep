/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:02:33 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/12 14:27:57 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *value)
{
	t_philo	*philo;

	philo = (t_philo *)value;
	ft_sleep(philo->table->t_start - ft_current_time());
	if (philo->id % 2 == 0)
		ft_sleep(10);
	while (philo->table->end == 0)
	{
		ft_printer(philo, "is thinking", 0);
		pthread_mutex_lock(philo->left_fork);
		ft_printer(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->right_fork);
		ft_printer(philo, "has taken a fork", 0);
		ft_printer(philo, "is eating", 0);
		ft_sleep(philo->table->t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (philo->table->meals_n)
			philo->t_eaten++;
		philo->last_meal = ft_current_time();
		ft_printer(philo, "is sleeping", 0);
		ft_sleep(philo->table->t_sleep);
	}
}

void	*controller_routine(void *value)
{
	t_send	*send;
	int		i;
	int		n_finish_eat;

	send = (t_send *)value;
	ft_sleep(send->table->t_start - ft_current_time());
	i = 0;
	n_finish_eat = 0;
	while (1)
	{
		if (i == send->table->ph_n)
		{
			if (n_finish_eat == send->table->ph_n)
			{
				pthread_mutex_lock(&send->table->mtx_end);
				send->table->end = 1;
				pthread_mutex_unlock(&send->table->mtx_end);
			}
			i = 0;
			n_finish_eat = 0;
		}
		if (send->philos[i]->dead || (ft_current_time() - send->philos[i]->last_meal) > send->table->t_die)
		{
			pthread_mutex_lock(&send->table->mtx_end);
			ft_printer(send->philos[i], "died", 1);
			pthread_mutex_unlock(&send->table->mtx_end);
			ft_close(send);
		}
		if (send->philos[i]->t_eaten >= send->table->meals_n && send->table->meals_n > 0)
			n_finish_eat++;
		i++;
	}
}
