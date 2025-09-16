/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:22:25 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/16 18:20:41 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/server.h"

void	recreate_binary(int b)
{
	static int	index = 0;

	if (!index)
		g_server.binary = ft_calloc(BYTE_SIZE + 1, sizeof(unsigned char));
	if (!g_server.binary)
		ft_free(&g_server.binary);
	g_server.binary[index++] = b;
	if (index == BYTE_SIZE)
	{
		g_server.ascii = ft_atoi_base(g_server.binary, "01");
		write(1, &g_server.ascii, 1);
		index = 0;
		ft_free(&g_server.binary);
	}
}
