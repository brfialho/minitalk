/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:21:51 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/16 18:55:30 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/server.h"

void	get_binary(int signo, siginfo_t *info, void *context)
{
	int	b;

	if (signo == SIGUSR1)
		b = '0';
	if (signo == SIGUSR2)
		b = '1';
	recreate_binary(b);
	kill(info->si_pid, SIGUSR1);
	(void)context;
}
