/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/16 18:59:29 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/client.h"

t_client	g_client;

int	main(int argc, char **argv)
{
	if (argc != 3 || ft_atoi(argv[1]) < 1)
		exit(1);
	g_client.signals = 0;
	g_client.awk = 0;
	signal(SIGUSR1, sighandler);
	send_str(ft_atoi(argv[1]), (unsigned char *)argv[2]);
	ft_printf("\n✅ Done.\n%d Signals recieved. %d chars sent.\n \
		No issues detected.\n", g_client.signals, (g_client.signals / 8) - 1);
}
