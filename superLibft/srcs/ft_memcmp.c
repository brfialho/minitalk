/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:42:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 16:41:57 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (n-- && *(char *)s1++ == *(char *)s2++)
		;
	return ((unsigned char)*(char *)--s1 - (unsigned char)*(char *)--s2);
}

// "hello\0"
// "hello\0"
// n 100