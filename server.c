/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/11 15:11:27 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/server.h"

int g_client_pid = 0;

// SERVER
// 		GET PID
//      PAUSE
//      LETRA / C
//      SEND
//		LETRA /C
//		SEND
//      ...
//		LETRA / 100
//		GET PID / PAUSE



// CLIENT
//		100

// SEND
// PAUSE
// SEND
// PAUSE
// ...
// SEND 100
// END

// int get_client_pid(void)
// {
	
// 	return (0);
// }

void  get_client_pid(int signo, siginfo_t *info, void *context)
{
	g_client_pid = info->si_pid;
	kill(g_client_pid, SIGUSR1);
	(void)signo;
	(void)context;
}

void listen_for_pid(void)
{
	t_sa sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = get_client_pid;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	pause();
}


int main(void) 
{
	ft_printf("SERVER PID: %d\n", getpid());
	listen_for_pid();
	ft_printf("CLIENT PID: %d\n", g_client_pid);
}
