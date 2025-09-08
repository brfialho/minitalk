/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/08 15:57:37 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/client.h"

void sighandler(int signum);

int main(int argc, char **argv)
{
	// int pid;

	// pid = getpid();

	// signal(SIGINT, sighandler);
	// while (!sleep(1) && printf("Client pid: %d\n", pid));	

	int pid = atoi(argv[1]);
	printf ("PID: %d\n", pid);
	kill(pid, SIGUSR1);
	(void)argc;
	(void)argv;
}
