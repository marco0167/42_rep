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
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
#include <signal.h>

/*****************************************************************************
*                                     Macros                                 *
*****************************************************************************/

# define MAX_PHILOS 200
# define STR_MAX_PHILOS "200"

# define STR_USAGE "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"
# define STR_ERR_INPUT "Error: Invalid input\n"
# define STR_ERR_NUM_PHILOS "Error: number of philosophers must be between \
1 and 200\n"

/*****************************************************************************
*                                     Struct                                 *
*****************************************************************************/

typedef struct s_table
{
	int				num_philos;
	int				pid;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	sem_t			*dead;
	sem_t			*forks;
	sem_t			*print;
	int				philos_eaten;
	int				*philos_pid;
	long long		start;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				pid;
	int				meals;
	int				fork_num;
	long long		last_meal;
	short			is_full;
	t_table			*table;
}					t_philo;

int			is_valid_input(int ac, char **av);
int			ft_validity_checker(int ac, char **av);
int			ft_atoi(const char *str);
int			ft_initializer(int ac, char **av, t_table *table);

long long	ft_current_time(void);
void		ft_sleep(int ms);

void		ft_close(t_table *table, t_philo *philos);

void		ft_wait_start(long long start);
void		ft_printer(t_philo *philo, char *str);
void		ft_philo_act(t_philo *philo);
void		*ft_philo_routine(void *arg);
void		*ft_controller(void *arg);

void		ft_philo_process(t_philo *philo);

#endif
