/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/14 00:18:32 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/client.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		exit(1);
	signal(SIGUSR1, sighandler);
	send_str(ft_atoi(argv[1]), (unsigned char *)argv[2]);
	ft_printf("\n✅ Done. No issues detected.\n");
}
