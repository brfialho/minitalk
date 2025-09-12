/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:17:24 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/12 16:30:06 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

// WARNING !! ft_itoa_base doesnt work for INT_MIN

static int	count_digits(int n, int len)
{
	int	count;

	count = 1;
	if (n < 0 && count++)
		n *= -1;
	while (n / len && count++)
		n /= len;
	return (count);
}

static int	check_sign(int *n, char *str)
{
	if (*n < 0)
	{
		*str = '-';
		*n *= -1;
		return (1);
	}
	return (0);
}

char	*ft_itoa_base(int n, char *base)
{
	int		i;
	int		len;
	int		base_len;
	char	*str;

	i = 0;
	base_len = ft_strlen(base);
	len = count_digits(n, base_len);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i += check_sign(&n, str);
	while (len-- > i && n / base_len)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	str[len] = base[n % base_len];
	return (str);
}

// int main(int argc, char **argv)
// {
// 	ft_itoa_base(ft_atoi(argv[1]), "0123456789ABCDEF");
// 	(void)argc;
// }