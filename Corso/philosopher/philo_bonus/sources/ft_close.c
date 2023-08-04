/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:07:14 by mcoppola          #+#    #+#             */
/*   Updated: 2023/08/04 16:27:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_close(t_table *table, t_philo *philos)
{
	free(table->forks);
	// free(&table->print);
	free(philos);
	free(table);
}
