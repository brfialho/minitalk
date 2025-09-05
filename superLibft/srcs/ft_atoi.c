/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 04:16:18 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_atoi(const char *nptr)
{
	int	sum;
	int	sign;

	sign = 1;
	sum = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
		sum = sum * 10 + *nptr++ - '0';
	return (sum * sign);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	printf("%d\n", ft_atoi(" 2147483647"));
// 	printf("%d\n", atoi("  2147483647"));
// }