/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:03:20 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/12 16:02:18 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	starter(t_send *send)
{
	int	i;

	i = 0;
	pthread_create(&send->table->c_tread, NULL, &controller_routine, send);
	while (i < send->table->ph_n)
	{
		pthread_create(&send->philos[i]->p_tread, NULL,
			&philo_routine, send->philos[i]);
		i++;
	}
	i = 0;
	pthread_join(send->table->c_tread, NULL);
	while (i < send->table->ph_n)
	{
		pthread_join(send->philos[i]->p_tread, NULL);
		i++;
	}
}
