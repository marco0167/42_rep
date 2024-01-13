/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:47:25 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/13 16:49:10 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_close(t_send *send)
{
	int	i;

	i = 0;
	while (i < send->table->ph_n)
	{
		pthread_mutex_destroy(&send->table->forks[i]);
		free(send->philos[i]);
		i++;
	}
	pthread_mutex_destroy(&send->table->mtx_end);
	pthread_mutex_destroy(&send->table->mtx_print);
	free(send->table->forks);
	free(send->table);
	free(send->philos);
	free(send);
	return (1);
}
