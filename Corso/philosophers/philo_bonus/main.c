/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:14:38 by mcoppola          #+#    #+#             */
/*   Updated: 2023/10/23 12:28:14 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	message(int id, char *act, t_config *config, int d)
{
	if (d)
		return (0);
	sem_wait(config->print_lock);
	printf("%lld %d %s\n", (now_ts() - config->start_time), id, act);
	sem_post(config->print_lock);
	return (0);
}

void	wait_procs(t_config *config, t_philo *philos)
{
	int	i;
	int	p;

	i = -1;
	while (++i < config->n_philo)
	{
		waitpid(-1, &p, 0);
		if (p != 0)
		{
			i = -1;
			while (++i < config->n_philo)
				kill(philos[i].proc, SIGTERM);
			break ;
		}
	}
}

int	start(t_config *config, t_philo *philos, int n_philo)
{
	int	i;

	i = -1;
	config->start_time = now_ts() + (config->n_philo * 2 * 10);
	while (++i < n_philo)
	{
		philos[i].proc = fork();
		if (philos[i].proc < 0)
			return (1);
		if (philos[i].proc == 0)
			work(&philos[i]);
	}
	wait_procs(config, philos);
	return (0);
}

int	_close(t_config *c, t_philo *p, char *msg)
{
	int	i;

	sem_close(c->print_lock);
	if (p && p[0].forks)
		sem_close(p[0].forks);
	sem_close(c->check);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_CHECK);
	if (p)
		free(p);
	if (c)
		free(c);
	if (msg)
	{
		i = -1;
		while (msg[++i])
			continue ;
		write(1, msg, i);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_config	*config;
	t_philo		*philos;
	sem_t		*forks;

	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_CHECK);
	if (argc < 5)
		return (_close((void *)0, (void *)0, "not enough args\n"));
	config = (t_config *)malloc(sizeof(t_config));
	if (!config)
		return (_close((void *)0, (void *)0, "config error\n"));
	if (parse_args(config, argc, argv))
		return (_close(config, (void *)0, "args error\n"));
	philos = (t_philo *)malloc(config->n_philo * sizeof(t_philo));
	if (!philos)
		return (_close(config, (void *)0, "philo error\n"));
	forks = sem_open(SEM_FORKS, O_CREAT, S_IRWXU, config->n_philo);
	init_philoers(config, philos, forks);
	if (start(config, philos, config->n_philo))
		return (_close(config, (void *)0, "start error\n"));
	return (_close(config, philos, (void *)0));
}