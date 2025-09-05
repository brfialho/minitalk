/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:12:32 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static	char	*ft_int_min(void)
{
	char	*s;

	s = ft_calloc(12, 1);
	if (!s)
		return (0);
	ft_memcpy(s, "-2147483648\0", 12);
	return ((char *)s);
}

static int	ft_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n / 10 && size++)
		n /= 10;
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*s;

	if (n == -2147483648)
		return ((char *)ft_int_min());
	i = 0;
	size = ft_size(n);
	s = ft_calloc(size + 1, 1);
	if (!s)
		return (0);
	if (n < 0)
	{
		n *= -1;
		s[i++] = '-';
	}
	while (i < size)
	{
		s[size-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf ("%s\n", ft_itoa(2147483647));
// }