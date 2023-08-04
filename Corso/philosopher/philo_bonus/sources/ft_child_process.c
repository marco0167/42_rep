/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:23:35 by mcoppola          #+#    #+#             */
/*   Updated: 2023/08/04 20:50:03 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_process(t_philo *philo)
{
	while (1)
	{
		if (philo->fork_num == 0)
			printf("Sono %d e sto pensando\n", philo->pid);
		if (philo->fork_num < 2)
		{
			if (!sem_wait(philo->table->forks))
				philo->fork_num++;
			if (ft_current_time() - philo->last_meal
				> philo->table->time_to_die)
			{
				printf("Sono %d e sono morto\n", philo->pid);
				while (1)
				{
					if (sem_wait(philo->table->dead) == 0)
						break ;
				}
				break ;
			}
			if (philo->fork_num == 2)
			{
				printf("Sono %d e ho preso 2 forchette\n", philo->pid);
				philo->last_meal = ft_current_time();
				ft_sleep(philo->table->time_to_eat);
				philo->fork_num = 0;
				sem_post(philo->table->forks);
				sem_post(philo->table->forks);
				printf("Sono %d e dormo\n", philo->pid);
				ft_sleep(philo->table->time_to_sleep);
			}
		}
	}
	printf("Sono %d e sono morto\n", philo->pid);
}
