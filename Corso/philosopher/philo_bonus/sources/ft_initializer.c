/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:49:17 by mcoppola          #+#    #+#             */
/*   Updated: 2023/08/04 20:48:08 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_init(t_table *table)
{
	t_philo	philo;

	philo.pid = getpid();
	philo.meals = 0;
	philo.table = table;
	philo.fork_num = 0;
	philo.last_meal = table->start;
	ft_philo_process(&philo);// Qui il processo figlio esegue il codice del filosofo
}

void	ft_philos_init(t_table *table)
{
	int	i;
	int	child_pid;

	i = -1;
	child_pid = 1;
	while (++i < table->num_philos)
	{
		if (child_pid > 0)
			child_pid = fork(); // Se processo padre, fork() ritorna il pid del figlio,
		if (child_pid > 0)
		{
			table->philos_pid[i] = child_pid;// Se processo padre stampa il suo pid e quello del figlio
			sem_post(table->forks);
		}
		else if (child_pid == 0)
		{
			ft_philo_init(table);// Eseguo línizializzazione del processo figlio
			break ;
		}
	}
}

int	ft_table_init(t_table *table, int ac, char **av)
{
	int	i;

	i = -1;
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->num_meals = ft_atoi(av[5]);
	else
		table->num_meals = -1;
	table->philos_eaten = 0;
	table->pid = getpid();
	table->philos_pid = malloc(sizeof(int) * table->num_philos);
	table->start = ft_current_time() + (table->num_philos * 2 * 10);
	table->print = sem_open("/print", O_CREAT, 0644, 1);
	table->dead = sem_open("/dead", O_CREAT, 0644, 1);
	sem_post(table->dead);
	table->forks = sem_open("/forks", O_CREAT, 0644, table->num_philos);
	if (table->forks == SEM_FAILED)
		return (1);
	return (0);
}

int	ft_initializer(int ac, char **av, t_table *table)
{
	int	pid;
	int	num;

	if (ft_table_init(table, ac, av))
		return (1);
	ft_philos_init(table);
	num = table->num_philos-1;
	// ft_thread_starter(philos, table);
	// ft_controller_start(&send);
	pid = getpid();
	if (pid == table->pid)
	{
		while (1)
		{
			if (!sem_wait(table->dead))
			{
				sem_post(table->dead);
				printf("Sono il padre e sono vivo\n");
			}
			else
			{
				printf("Sono-----------------------------\n");
				break ;
			}
			printf("Sono il padre e sto aspettando\n");
			ft_sleep(500);
		}
		printf("Sono il padre e sono morto\n");
		while (num >= 0)
		{
			kill(table->philos_pid[num], SIGKILL);
			num--;
		}

		kill(table->pid, SIGKILL);
	}
	return (0);
}
