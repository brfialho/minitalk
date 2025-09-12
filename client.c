/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/12 17:08:02 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/client.h"

void sighandler(int signum)
{
	ft_printf("Confirmation recieved\n");
	exit(0);
	(void)signum;
}

char	*fill_zeros(char *binary)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(binary);
	if (len == BYTE_SIZE)
		return (binary);
	new = ft_calloc(BYTE_SIZE + 1, sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (i < BYTE_SIZE)
	{
		if (i < BYTE_SIZE - len)
			new[i++] = '0';
		else
			new[i++] = *binary++;
	}
	free(binary - len);
	return (new);
}

int main(int argc, char **argv)
{
	// TO DO
	// send pid to server then comuninacate -> pause -> comunicate...
	int 	pid;
	char	*binary;
	char	*str;
	
	if (argc != 3)
		exit(1);

	pid = atoi(argv[1]);
	str = argv[2];
	ft_printf ("SERVER PID: %d\nCLIENT PID: %d\nSTR: %s\n", pid, getpid(), str);
	//signal(SIGUSR1, sighandler);
	kill(pid, SIGUSR1);
	//pause();

	binary = fill_zeros(ft_itoa_base(argv[2][0], "01"));
	//binary = ft_itoa_base(argv[2][0], "01");
	ft_printf("%s\n", binary);
	free(binary);
	

	// itoa = 97 -> 01010110 -> "01010110"
	// send
	// atob = "01010110" -> 97
	
	// int i = str[0];
	// int j = 0;

// 	while (j++ < i)
// 	{
// 		usleep(100);
// 		kill(pid, SIGUSR1);
// 		usleep(100);
// 	}
// 	kill(pid, SIGUSR2);
}
