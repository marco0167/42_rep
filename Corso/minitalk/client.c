/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:44:57 by mcoppola          #+#    #+#             */
/*   Updated: 2023/03/28 17:10:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("Message printed correctly\n");
}

void	sig_sender(int c, pid_t pid)
{
	int	bit_counter;

	bit_counter = 0;
	while (bit_counter < 8)
	{
		if ((c & (1 << bit_counter)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_counter++;
		usleep(600);
	}
}

void	send_message(char *message, pid_t pid)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		sig_sender(message[i], pid);
		i++;
	}
	sig_sender('\0', pid);
}

int	main(int argc, char **argv)
{
	pid_t pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("Usage: ./client [server PID] [message]\n");
		return (0);
	}

	signal(SIGUSR1, sig_handler);
	send_message(argv[2], pid);
	// ft_printf("[server PID: %s] [message: %s]\n", argv[1], argv[2]);
}
