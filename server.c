/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/08 18:53:12 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/server.h"

void sighandler(int signum);



int main(void)
{
	printf("Server pid: %d\n", getpid());
	
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause();
}

void sighandler(int signum)
{
	static int letter = 0;
	
	if (signum == SIGUSR1)
		letter++;
	if (signum == SIGUSR2)
	{
		printf("%c\n", letter);
		letter = 0;
	}
}

// void sighandler(int signum)
// {
// 	printf("OLA%d\n", signum);
// 	sleep(1);
// 	exit(1);
// }