/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:47:26 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memset(void	*s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n--)
		*str++ = c;
	return (s);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	test[10];
// 	ft_memset(test, 'a', 4);
// 	printf("%s\n", test);
// 	memset(test, 'b', 6);
// 	printf("%s\n", test);
// }