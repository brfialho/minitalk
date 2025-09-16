/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/16 18:33:24 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/server.h"

t_server	g_server;

int	main(void)
{
	g_server.ascii = 0;
	g_server.binary = NULL;
	ft_printf("\n#######  SERVER PID: %d  #######\n\n", getpid());
	listen_for_string();
	while (1)
		pause();
}
