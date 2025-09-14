/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/14 00:16:10 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/client.h"

void	send_str(int pid, unsigned char *s)
{
	unsigned char	*binary;

	while (*s)
	{
		binary = fill_byte(itoba(*s++));
		if (!binary)
			return ;
		send_bit(pid, binary);
		free(binary);
	}
	if (!*s)
		send_bit(pid, (unsigned char *)"00001010");
}
