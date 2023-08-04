/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:12:55 by mcoppola          #+#    #+#             */
/*   Updated: 2023/07/25 19:22:31 by mcoppola         ###   ########.fr       */
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
