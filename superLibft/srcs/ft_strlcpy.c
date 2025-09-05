/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:03:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
// #include <stdio.h>
// #include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;

	len = ft_strlen(src);
	if (!size)
		return (len);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = 0;
	return (len);
}

// int	main(void)
// {
// 	char tab[10000];
// 	printf("%zu %s\n", ft_strlcpy(tab, "aaaaaaaaaaaaaaaaaaaaa", 0), tab);
// 	printf("%zu %s\n", strlcpy(tab, "aaaaaaaaaaaaaaaaaaaaa", 0), tab);
// }