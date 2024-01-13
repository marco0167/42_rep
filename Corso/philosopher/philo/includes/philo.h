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
	int				ph_n;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				meals_n;
	pthread_mutex_t	*forks;
	pthread_t		c_tread;
	long long		t_start;
	pthread_mutex_t	mtx_end;
	int				end;
	pthread_mutex_t	mtx_print;
}					t_table;

typedef struct s_philo
{
	pthread_t		p_tread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		last_meal;
	int				t_eaten;
	int				dead;
	int				id;
	t_table			*table;
}					t_philo;

typedef struct s_send
{
	t_philo	**philos;
	t_table	*table;
}				t_send;

int			is_valid_input(int ac, char **av);
int			ft_validity_checker(int ac, char **av);
int			ft_atoi(const char *str);

/* starters */

void		starter(t_send *send);

/* init */

void		init(t_send *send);

/* routines */

void		*philo_routine(void *value);
void		*controller_routine(void *value);

/* utils */

long long	ft_current_time(void);
void		ft_sleep(int ms);
void		ft_printer(t_philo *philo, char *str, int isDead);

/*  close */

int			ft_close(t_send *send);

#endif
