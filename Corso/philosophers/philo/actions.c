/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrancav <lfrancav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:52:25 by lfrancav          #+#    #+#             */
/*   Updated: 2023/07/13 15:58:16 by lfrancav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_act(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->fork_ids[0]]);
	message(philo->id, TOOK_FORK, philo->config, philo->config->stop);
	pthread_mutex_lock(&philo->forks[philo->fork_ids[1]]);
	message(philo->id, TOOK_FORK, philo->config, philo->config->stop);
	message(philo->id, EATING, philo->config, philo->config->stop);
	pthread_mutex_lock(&philo->rw_mutex);
	philo->last_meal = now_ts();
	(philo->meals_counter)++;
	if (philo->meals_counter == philo->config->tme)
		philo->full = 1;
	pthread_mutex_unlock(&philo->rw_mutex);
	ft_sleep(philo->config->t_eat);
	message(philo->id, SLEEPING, philo->config, philo->config->stop);
	pthread_mutex_unlock(&philo->forks[philo->fork_ids[0]]);
	pthread_mutex_unlock(&philo->forks[philo->fork_ids[1]]);
	ft_sleep(philo->config->t_sleep);
}

void	lone_philo_act(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->fork_ids[0]]);
	message(philo->id, TOOK_FORK, philo->config, philo->config->stop);
	ft_sleep(philo->config->t_die);
}
