/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:14:41 by mcoppola          #+#    #+#             */
/*   Updated: 2023/10/12 14:53:54 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_act(t_philo *philo)
{
	sem_wait(philo->forks);
	message(philo->id, TOOK_FORK, philo->config, philo->config->stop);
	sem_wait(philo->forks);
	message(philo->id, TOOK_FORK, philo->config, philo->config->stop);
	message(philo->id, EATING, philo->config, philo->config->stop);
	sem_wait(philo->config->check);
	philo->last_meal = now_ts();
	(philo->meals_counter)++;
	if (philo->meals_counter == philo->config->tme)
		philo->full = 1;
	sem_post(philo->config->check);
	ft_sleep(philo->config->t_eat);
	message(philo->id, SLEEPING, philo->config, philo->config->stop);
	sem_post(philo->forks);
	sem_post(philo->forks);
	ft_sleep(philo->config->t_sleep);
}

void	lone_philo_act(t_philo *philo)
{
	sem_wait(philo->forks);
	message(philo->id, TOOK_FORK, philo->config, philo->config->stop);
	ft_sleep(philo->config->t_die);
}
