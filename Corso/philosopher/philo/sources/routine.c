/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:02:33 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/11 20:51:13 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *value)
{
	t_philo	*philo;

	philo = (t_philo *)value;
	printf("Creato philo ---%d -- %lld -- %d\n\n\n", philo->id, philo->last_meal, philo->t_eaten);
}
