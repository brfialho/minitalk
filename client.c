/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/13 23:09:52 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/client.h"

static int	count_digits(int n)
{
	int	count;

	count = 1;
	while (n / 2 && count++)
		n /= 2;
	return (count);
}

unsigned char *itoba(int n)
{
	unsigned char	*binary;
	int				len;

	len = count_digits(n);
	binary = ft_calloc(len + 1, sizeof(unsigned char));
	if (!binary)
		return (0);
	while (len-- && n / 2)
	{
		binary[len] = "01"[n % 2];
		n /= 2;
	}
	binary[len] = "01"[n % 2];
	return (binary);
}

void sighandler(int signum)
{
	static int i = 0;
	static int n = -1;
	
	usleep(250);
	if (!(i % 8))
		n++;
	ft_printf("Confirmation %d recieved. %d chars send\n", i++, n);
	(void)signum;
}

void send_bit(int pid, unsigned char* binary)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		if (binary[i] == '0')
			kill(pid, SIGUSR1);
		if (binary[i] == '1')
			kill(pid, SIGUSR2);
		pause();
	}
}
void send_str(int pid, unsigned char* s)
{
	unsigned char *binary;

	while (*s)
	{
		binary = fill_byte(itoba(*s++));
		if (!binary)
			return ;
		send_bit(pid, binary);
	}
	if (!*s)
		send_bit(pid, (unsigned char*)"00001010");
	free(binary);
}
int main(int argc, char **argv)
{
	if (argc != 3)
		exit(1);

	signal(SIGUSR1, sighandler);
	send_str(ft_atoi(argv[1]), (unsigned char*)argv[2]);
	ft_printf("\n✅ Done. No issues detected.\n");
}
