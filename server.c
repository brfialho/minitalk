/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/13 19:29:26 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/server.h"

t_mini g_mini;

static int	get_digit(char digit, const char *base)
{
	int	value;

	value = -1;
	while (base[++value])
		if (base[value] == digit)
			return (value);
	return (-1);
}

unsigned char	ft_atoi_b(unsigned char *nptr, const char *base)
{
	size_t	b_len;
	int		sign;
	int		sum;
	unsigned char c;

	b_len = ft_strlen(base);
	sum = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '+' || *nptr == '-' )
		if (*nptr++ == '-')
			sign *= -1;
	while (get_digit(*nptr, base) >= 0)
		sum = sum * b_len + get_digit(*nptr++, base);
	c = (unsigned char)sum;
	return (c);
}
void	recreate_binary(int b)
{
	static int	index = 0;
	
	g_mini.binary[index++] = b;
	if (index == 8)
	{
		g_mini.ascii = ft_atoi_b(g_mini.binary, "01");
		//ft_printf("\nINT %d ", g_mini.ascii);
		write(1, &g_mini.ascii, 1);
		//ft_printf("%c", g_mini.ascii);
		index = 0;
	}
}

void  get_client_pid(int signo, siginfo_t *info, void *context)
{
	g_mini.pid = info->si_pid;
	
	//ft_printf("GOT PID\n");
	
	(void)signo;
	(void)context;
}

void  get_binary(int signo, siginfo_t *info, void *context)
{
	int b;
	//static int teste = 0;

	//ft_printf("GOT SIGNAL %d ", teste++);
	if (signo == SIGUSR1)
		b = '0';
	if (signo == SIGUSR2)
		b = '1';

	//ft_printf("BINARY: %d\n", b - 48);
	recreate_binary(b);
	
	kill(g_mini.pid, SIGUSR1);

	(void)info;
	(void)context;
}

void listen_for_pid(void)
{
	t_sa sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = get_client_pid;
	sa.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &sa, NULL) && ft_printf("Sigaction Err 1\n"))
		exit(1);
	pause();
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
	g_mini.binary = ft_calloc(9, sizeof(unsigned char));
	if (!g_mini.binary)
		exit (1);
}
int main(void) 
{
	ft_printf("SERVER PID: %d\n", getpid());
	mini_init();
	listen_for_pid();
	listen_for_string();
	kill(g_mini.pid, SIGUSR1);
	while (1)
		pause();
}
