/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:48:45 by codespace         #+#    #+#             */
/*   Updated: 2023/06/14 10:21:19 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// const int	philo_num = 5;
// int numero[5] = {1, 1, 1, 1, 1};
// int T_E = 3;
// pthread_mutex_t mutex;

// void	*process(void *arg)
// {
// 	int num = *(int *)arg;
// 	int *result = malloc(sizeof(int));
// 	int i;

// 	*result = num;
// 	if (num == 0)
// 	{
// 		if (numero[num] && numero[num + 1])
// 		{
// 			pthread_mutex_lock(&mutex);
// 			numero[num] = 0;
// 			numero[num + 1] = 0;
// 			pthread_mutex_unlock(&mutex);
// 			printf("PHILOSOPHER %d is eating\n", num);
// 			sleep(T_E);
// 			pthread_mutex_lock(&mutex);
// 			numero[num] = 1;
// 			numero[num + 1] = 1;
// 			pthread_mutex_unlock(&mutex);
// 		}
// 		else
// 			printf("PHILOSOPHER %d not eat\n", num);

// 	}
// 	else
// 	{
// 		if (numero[num] && numero[philo_num - 1])
// 		{
// 			pthread_mutex_lock(&mutex);
// 			numero[num] = 0;
// 			numero[philo_num - 1] = 0;
// 			pthread_mutex_unlock(&mutex);
// 			printf("PHILOSOPHER %d is eating\n", num);
// 			sleep(T_E);
// 			pthread_mutex_lock(&mutex);
// 			numero[num] = 1;
// 			numero[philo_num - 1] = 1;
// 			pthread_mutex_unlock(&mutex);
// 		}
// 		else
// 			printf("PHILOSOPHER %d not eat\n", num);
// 	}

// 	// printf("Thread %d\n", num);
// 	return ((void *)result);
// }

// void	philo_routine(t_philo *philo, t_data *data)
// {
// 	if (philo->id == 0)
// 	{
// 		data->forks[]
// 	}
// }

void	*process(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("----------------------\n");
	// printf("Thread ID %d Created\n", philo->id);
	// printf("Right fork %d\n", *philo->right_fork);
	// printf("Left fork %d\n", *philo->left_fork);
	// printf("----------------------\n");
	while (philo->data->end == 0)
	{
		if (philo->status == 0)
		{
			if (philo->is_tinking == 0)
			{
				printf("PHILOSOPHER %d is thinking\n", philo->id);
				philo->is_tinking = 1;
			}
			sleep(1.6);
			philo->status = 1;
		}
		else if (philo->status == 1)
		{
			// printf("-----------------------\n");
			// printf("PHILOSOPHER %d\n", philo->id);
			// printf("left fork %d\n", philo->data->forks[philo->left_fork]);
			// printf("right fork %d\n", philo->data->forks[philo->right_fork]);
			// printf("-----------------------\n");
			if (philo->data->forks[philo->left_fork] == 1 && philo->data->forks[philo->right_fork] == 1)
			{
				pthread_mutex_lock(philo->data->mutex);
				philo->data->forks[philo->left_fork] = 0;
				philo->data->forks[philo->right_fork] = 0;
				pthread_mutex_unlock(philo->data->mutex);
				printf("-----------------------\n");
				printf("PHILOSOPHER %d is eating------\n", philo->id);
				printf("-----------------------\n");
				sleep(philo->data->time_to_eat);
				pthread_mutex_lock(philo->data->mutex);
				philo->data->forks[philo->left_fork] = 1;
				philo->data->forks[philo->right_fork] = 1;
				pthread_mutex_unlock(philo->data->mutex);
				philo->eat_count++;
				philo->is_tinking = 0;
				philo->status = 2;
			}
			else
			{
				printf("PHILOSOPHER %d is waiting\n", philo->id);
				philo->status = 0;
			}
		}
		else if (philo->status == 2)
		{
			printf("PHILOSOPHER %d is sleeping\n", philo->id);
			sleep(philo->data->time_to_sleep);
			philo->status = 0;
		}
		if (philo->eat_count == philo->data->must_eat)
			philo->data->eat_count++;
		if (philo->data->eat_count == philo->data->num_philo)
			philo->data->end = 2;
	}
	printf("thread %d ended\n", philo->id);
	return (NULL);
}

void	init_philo(t_philo *philos, int id, t_data *data)
{
	t_philo	*philo;

	data->forks[id] = 1;
	philo = &philos[id];
	philo->id = id;
	philo->left_fork = id;
	if (id == data->num_philo - 1)
		philo->right_fork = 0;
	else
		philo->right_fork = id + 1;
	philo->eat_count = 0;
	philo->is_tinking = 0;
	philo->status = 0;
	philo->data = data;
	// pthread_create(&philo->thread, NULL, &process, (void *)philo);
}

void	init_data(int argc, char **argv, t_data *data)
{
	int 	i;
	pthread_mutex_t mutex;

	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->end = 0;
	printf("Number of philosophers: %d\n", data->num_philo);
	data->forks = malloc(sizeof(int) * data->num_philo);
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	data->mutex = &mutex;
	pthread_mutex_init(data->mutex, NULL);
	i = 0;
	while (i < data->num_philo)
	{
		init_philo(data->philos, i, data);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		*res;
	int 	i;

	if (argc < 5 || argc > 6)
	{
		printf("\nUsage: ./philo number_of_philosophers    time_to_die    time_to_eat    time_to_sleep    number_of_times_each_philosopher_must_eat\n");
		printf("\n[number_of_times_each_philosopher_must_eat] is OPTIONAL\n\n");
		return (1);
	}

	data = malloc(sizeof(t_data));
	init_data(argc, argv, data);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_create(&data->philos[i].thread, NULL, &process, (void *)&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	printf("ENDED with %d\n", data->end);
	pthread_mutex_destroy(data->mutex);
	printf("ENDED222222 with %d\n", data->end);


	// pthread_mutex_init(&mutex, NULL);
	// for (i = 0; i < philo_num; i++)
	// {
	// 	int *num = malloc(sizeof(int));
	// 	*num = i;
	// 	if (pthread_create(&th[i], NULL, &process, num) != 0)
	// 	{
	// 		return (1);
	// 	}
	// }

	// for (i = 0; i < philo_num; i++)
	// {
	// 	if (pthread_join(th[i], (void **)&res) != 0)
	// 	{
	// 		return (1);
	// 	}
	// 	printf("result %d\n", *res);
	// }

	// pthread_mutex_destroy(&mutex);

	return 0;
}
