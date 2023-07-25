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

/*****************************************************************************
*                                     Macros                                 *
*****************************************************************************/

# define MAX_PHILOS 250
# define STR_MAX_PHILOS "250"

# define STR_USAGE "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"
# define STR_ERR_INPUT "Error: Invalid input\n"
# define STR_ERR_NUM_PHILOS "Error: number of philosophers must be between \
1 and 250\n"

/*****************************************************************************
*                                     Struct                                 *
*****************************************************************************/

typedef struct s_table
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				dead;
	int				philos_eaten;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*philos_eaten_mutex;
	long long		start;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	short			is_full;
	pthread_t		thread;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	pthread_mutex_t	*read_write;
	t_table			*table;
}					t_philo;

typedef struct s_send
{
	t_philo	*philos;
	t_table	*table;
}				t_send;

int			is_valid_input(int ac, char **av);
int			ft_validity_checker(int ac, char **av);
int			ft_atoi(const char *str);
void		ft_initializer(int ac, char **av, t_table *table, t_philo *philos);

void		ft_thread_starter(t_philo *philos, t_table *table);
void		ft_controller_start(t_send *send);
long long	ft_current_time(void);

void		ft_close(t_table *table, t_philo *philos);

void		ft_wait_start(long long start);
void		ft_printer(t_philo *philo, char *str);
void		ft_philo_act(t_philo *philo);
void		*ft_philo_routine(void *arg);
void		*ft_controller(void *arg);

#endif
