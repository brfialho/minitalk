/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/08 20:57:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/client.h"

void sighandler(int signum);

int main(int argc, char **argv)
{
	// TO DO
	// send pid to server then comuninacate -> pause -> comunicate...
	int 	pid;
	char	*str;
	
	if (argc != 3)
		exit(1);

	pid = atoi(argv[1]);
	str = argv[2];
	printf ("PID: %d\nSTR: %s\n", pid, str);
	//kill(pid, SIGUSR1);
	int i = str[0];
	int j = 0;

	while (j++ < i)
	{
		usleep(100);
		kill(pid, SIGUSR1);
		usleep(100);
	}
	kill(pid, SIGUSR2);
}
