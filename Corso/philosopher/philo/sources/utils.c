/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:26:16 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/12 13:52:32 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_current_time(void)
{
	struct timeval	current_time;
	long long		time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000;
	return (time);
}

void	ft_sleep(int ms)
{
	long long	s;

	s = ft_current_time() + ms;
	while (ft_current_time() < s)
		usleep(100);
}

void	ft_printer(t_philo *philo, char *str, int isDead)
{
	if (philo->table->end)
		return ;
	pthread_mutex_lock(&philo->table->mtx_print);
	if (philo->table->end)
		return ;
	printf("%lld %d %s\n", ft_current_time() - philo->table->t_start,
		philo->id + 1, str);
	if (isDead)
		philo->table->end = 1;
	pthread_mutex_unlock(&philo->table->mtx_print);
}
