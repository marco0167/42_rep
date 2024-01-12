/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:47:25 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/12 14:14:06 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_close(t_send *send)
{
	int	i;

	i = 0;
	while (i < send->table->ph_n)
	{
		pthread_mutex_destroy(&send->table->forks[i]);
		free(send->philos[i]);
		i++;
	}
	free(send->table->forks);
	free(send->table);
	free(send->philos);
	free(send);
	exit(0);
}
