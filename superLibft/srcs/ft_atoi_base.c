/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:52:52 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/11 19:43:24 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	get_digit(char digit, const char *base);

int	ft_atoi_base(const char *nptr, const char *base)
{
	size_t	b_len;
	int		sign;
	int		sum;

	b_len = ft_strlen(base);
	sum = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '+' || *nptr == '-' )
		if (*nptr++ == '-')
			sign *= -1;
	while (get_digit(*nptr, base) >= 0)
		sum = sum * b_len + get_digit(*nptr++, base);
	return (sum * sign);
}

static int	get_digit(char digit, const char *base)
{
	int	value;

	value = -1;
	while (base[++value])
		if (base[value] == digit)
			return (value);
	return (-1);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_atoi_base("   ---000001011010", "01"));	
// }