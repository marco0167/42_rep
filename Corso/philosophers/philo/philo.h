/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrancav <lfrancav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:52:42 by lfrancav          #+#    #+#             */
/*   Updated: 2023/07/13 16:03:31 by lfrancav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TOOK_FORK "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

typedef struct s_config
{
	long long		start_time;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				tme;
	int				stop;
	pthread_mutex_t	print_lock;
}	t_config;

typedef struct s_philo
{
	int				id;
	int				fork_ids[2];
	int				meals_counter;
	int				full;
	long long		last_meal;
	t_config		*config;
	pthread_mutex_t	rw_mutex;
	pthread_mutex_t	*forks;
}	t_philo;

typedef struct s_send
{
	t_config	*config;
	t_philo		*philos;
}	t_send;

int			parse_args(t_config *config, int argc, char *argv[]);
int			message(int id, char *act, t_config *config, int d);
int			ft_atoi(char *str);
long long	now_ts(void);
void		ft_sleep(int ms);
void		init_philoers(t_config *config,	t_philo *philos,
				pthread_mutex_t *forks);
void		*work(void *arguments);
void		philo_act(t_philo *philo);
void		lone_philo_act(t_philo *philo);
void		*controller(void *args);
void		wait_start(long long st);
void		destroy_mutexes(pthread_mutex_t *forks, t_philo *philos,
				int n_philo);

#endif
