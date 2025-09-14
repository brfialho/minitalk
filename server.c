/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/13 22:53:48 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/server.h"

t_mini g_mini;

void	recreate_binary(int b)
{
	static int	index = 0;
	
	if (!index)
		g_mini.binary = ft_calloc(BYTE_SIZE + 1, sizeof(unsigned char));
	if (!g_mini.binary)
		ft_free(&g_mini.binary);
	g_mini.binary[index++] = b;
	if (index == BYTE_SIZE)
	{
		g_mini.ascii = ft_atoi_base(g_mini.binary, "01");
		write(1, &g_mini.ascii, 1);
		index = 0;
		ft_free(&g_mini.binary);
	}
}

void  get_binary(int signo, siginfo_t *info, void *context)
{
	int b;

	usleep(250);
	g_mini.pid = info->si_pid;
	if (signo == SIGUSR1)
		b = '0';
	if (signo == SIGUSR2)
		b = '1';
	recreate_binary(b);
	kill(g_mini.pid, SIGUSR1);
	(void)context;
}

void listen_for_string(void)
{
	t_sa sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = get_binary;
	sa.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &sa, NULL) && ft_printf("Sigaction Err 2\n"))
		exit(2);
	if (sigaction(SIGUSR2, &sa, NULL) && ft_printf("Sigaction Err 3\n"))
		exit(3);
}

void mini_init(void)
{
	g_mini.pid = 0;
	g_mini.ascii = 0;
	g_mini.binary = NULL;
	//g_mini.binary = ft_calloc(9, sizeof(unsigned char));
	// if (!g_mini.binary)
	// 	exit (1);
}
int main(void) 
{
	ft_printf("SERVER PID: %d\n", getpid());
	mini_init();
	listen_for_string();
	while (1)
		pause();
}
