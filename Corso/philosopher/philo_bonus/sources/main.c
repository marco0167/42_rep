/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:14:07 by mcoppola          #+#    #+#             */
/*   Updated: 2023/08/04 16:26:10 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (!ft_validity_checker(ac, av))
		return (1);
	return (ft_initializer(ac, av, &table));
}

// int numm_process = 3;
// int main()
// {
// 	int return_value;
// 	int pid;
// 	int num;
// 	int	*pid_cont;

// 	pid_cont = malloc(sizeof(int) * numm_process);
// 	num = numm_process;
// 	printf("Forking process %d\n", getpid());
// 	while (num > 0)
// 	{
// 		if (pid > 0)
// 			pid = fork(); // Se processo padre, fork() ritorna il pid del figlio,
// 		if (pid > 0)// Se processo padre stampa il suo pid e quello del figlio
// 			pid_cont[num] = pid;
// 		// else if (pid == 0)// Se processo figlio stampa il suo pid e termina
// 		// {
// 		// 	printf("Child process pid = %d\n", getpid());// Eseguo il codice del processo figlio
// 		// 	break ;
// 		// }
// 		num--;
// 	}
// 	num = numm_process;
// 	if (pid > 0)
// 		while (num > 0)
// 		{
// 			printf("Child process %d\n", pid_cont[num]);
// 			num--;
// 		}
// }
