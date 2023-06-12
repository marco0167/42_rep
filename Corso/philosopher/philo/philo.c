/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:04 by mcoppola          #+#    #+#             */
/*   Updated: 2023/06/06 18:55:02 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_message(void *ptr, int *var)
{
	int		id;
	int		val;

	id = (int)ptr;
	var++;
	val = var;
	printf("Thread %d\n", val);
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t	thread[5];
	int rc, i, var=0;

	for (i = 0; i < 5; i++)
	{
		rc = pthread_create(&thread[i], NULL, print_message, ((void *)i, &var));
		printf("Creating thread! value %d\n", var);
		if (rc)
		{
			printf("Error: unable to create thread, %d\n", rc);
			exit(-1);
		}
	}
	return (0);
}
