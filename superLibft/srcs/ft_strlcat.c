/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:14:23 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	if (!dst)
		return (size + src_len);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	while (*src && size-- - 1 - dst_len > 0)
		dst++[dst_len] = *src++;
	dst[dst_len] = 0;
	return (dst_len + src_len);
}

// #include <bsd/string.h>
// #include <stdio.h>
// int	main(void)
// {	
// 	char dest[30];
// 	char dest2[30]; 
// 	memset(dest, 0, 30);
// 	memset(dest2, 0, 30);

// 	memset(dest, 98, 10);
// 	memset(dest2, 98, 10);
// 	char *src = "AAAAA";
// 	// char tab1[6] = "hello\0";
// 	// char tab2[6] = "hello\0";
// 	// char src1[] = "babababa";
// 	// char src2[] = "babababa";
// 	printf("%zu %s %s\n", strlcat(0, src, 0), dest2, src);
// 	printf("%zu %s %s\n", ft_strlcat(0, src, 0), dest, src);
// }
