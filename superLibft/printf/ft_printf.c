/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:40:19 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/16 20:31:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	argv;
	int		count;

	count = 0;
	va_start(argv, s);
	while (*s)
	{
		if (*s == '%' && pf_instr("cspdiuxX", *++s))
			count += pf_put(*s++, va_arg(argv, void *));
		else
			count += write(1, s++, 1);
	}
	va_end(argv);
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_printf("%d\n", 30);
// 	printf("%d\n", 30);
// 	ft_printf("%i\n", 052);
// 	printf("%i\n", 052);
// }

