/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:24 by mcoppola          #+#    #+#             */
/*   Updated: 2023/06/06 18:20:12 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct s_data;

typedef struct	s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	int				status;
	int				is_tinking;
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;

typedef struct	s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				eat_count;
	int				end;
	int				*forks;
	pthread_mutex_t	*mutex;
	t_philo			*philos;
}					t_data;

int	ft_atoi(const char *str);

#endif
