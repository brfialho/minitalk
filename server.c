/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/08 16:00:26 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/server.h"

void sighandler(int signum);

int main(int argc, char **argv)
{
	int pid;

	pid = getpid();

	printf("Server pid: %d\n", pid);
	
	signal(SIGUSR1, sighandler);
	while (1)
		pause();

	(void)argc;
	(void)argv;
}

void sighandler(int signum)
{
	printf("ALO %d\n", signum);
	sleep(1);
}

// void sighandler(int signum)
// {
// 	printf("OLA%d\n", signum);
// 	sleep(1);
// 	exit(1);
// }