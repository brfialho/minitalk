/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoba.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:14:21 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/14 00:14:54 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/client.h"

static int	count_digits(int n)
{
	int	count;

	count = 1;
	while (n / 2 && count++)
		n /= 2;
	return (count);
}

unsigned char	*itoba(int n)
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
