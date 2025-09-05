/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 23:25:14 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 18:13:37 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	pf_putstr(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0 ;
	while (s[count])
		write(1, &s[count++], 1);
	return (count);
}

int	pf_putptr(void *p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + pf_put_ul((unsigned long)p, "0123456789abcdef", 16));
}

int	pf_put(char c, void *s)
{
	if (c == 'c' || c == '%')
		return (write(1, &s, 1));
	if (c == 's')
		return (pf_putstr((char *)s));
	if (c == 'p')
		return (pf_putptr(s));
	if (pf_instr("id", c))
		return (pf_put_n((int)(long)s, "0123456789", 10));
	if (c == 'u')
		return (pf_put_un((unsigned int)(unsigned long)s, "0123456789", 10));
	if (c == 'x')
		return (pf_put_un((unsigned long)s, "0123456789abcdef", 16));
	return (pf_put_un((unsigned long)s, "0123456789ABCDEF", 16));
}
