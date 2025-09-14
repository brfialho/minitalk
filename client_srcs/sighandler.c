/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:13:47 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/14 00:15:16 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/client.h"

void	sighandler(int signum)
{
	static int	i = 0;
	static int	n = -1;

	usleep(250);
	if (!(i % 8))
		n++;
	ft_printf("Confirmation %d recieved. %d chars send\n", i++, n);
	(void)signum;
}
