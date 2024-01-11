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
}					t_table;

typedef struct s_philo
{
}					t_philo;

typedef struct s_send
{
	t_philo	*philos;
	t_table	*table;
}				t_send;

int			is_valid_input(int ac, char **av);
int			ft_validity_checker(int ac, char **av);
int			ft_atoi(const char *str);

#endif
