/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/13 17:43:01 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/client.h"

void sighandler(int signum)
{
	static int i = 0;
	ft_printf("Confirmation %d recieved\n", i++);
	(void)signum;
}
int send_str(int pid, char* s)
{
	int i;
	char *binary;

	while (*s)
	{
		binary = fill_byte(ft_itoa_base(*s++, "01"));
		if (!binary)
			return (0);
		i = -1;
		while (++i < 8)
		{
			if (binary[i] == '0' && printf (" I: %d\n", i))
				kill(pid, SIGUSR1);
			if (binary[i] == '1' && printf (" I: %d\n", i))
				kill(pid, SIGUSR2);
			pause();
		}
	}
	free(binary);
	return (1);
}
int main(int argc, char **argv)
{
	// TO DO
	// send pid to server then comuninacate -> pause -> comunicate...
	int 	pid;
	
	if (argc != 3)
		exit(1);

	// send pid
	pid = ft_atoi(argv[1]);;
	ft_printf ("SERVER PID: %d\nCLIENT PID: %d\nSTR: %s\n", pid, getpid(), argv[2]);
	
	// acklogene pid
	signal(SIGUSR1, sighandler);
	kill(pid, SIGUSR1);
	pause();

	send_str(pid, argv[2]);
}
