/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:12:42 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/14 00:14:33 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/client.h"

void	send_bit(int pid, unsigned char *binary)
{
	int	i;

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
