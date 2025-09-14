/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_for_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:21:06 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/14 00:16:59 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/server.h"

void	listen_for_string(void)
{
	t_sa	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = get_binary;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) && ft_printf("Sigaction Err 2\n"))
		exit(2);
	if (sigaction(SIGUSR2, &sa, NULL) && ft_printf("Sigaction Err 3\n"))
		exit(3);
}
