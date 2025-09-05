/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 23:20:00 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 18:13:37 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	pf_put_ul(unsigned long n, char *base, int len)
{
	if (n / len)
		pf_put_ul(n / len, base, len);
	write (1, &base[n % len], 1);
	return (pf_count_long(n, len));
}

int	pf_put_un(unsigned int n, char *base, int len)
{
	if (n / len)
		pf_put_un(n / len, base, len);
	write (1, &base[n % len], 1);
	return (pf_count_unsigned(n, len));
}

int	pf_put_n(int n, char *base, int len)
{
	int	count;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	count = pf_count_digits(n, len);
	if (n < 0 && write(1, "-", 1))
		n *= -1;
	if (n / len)
		pf_put_n(n / len, base, len);
	write (1, &base[n % len], 1);
	return (count);
}
