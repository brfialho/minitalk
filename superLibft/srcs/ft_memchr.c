/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:31:55 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if ((char)c == *(char *)s++)
			return ((void *)--s);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	printf("%d\n", *(char *)ft_memchr(s, 2 + 256, 3));
// 	printf("%d\n", *(char *)memchr(s, 2 + 256, 3));
// }
