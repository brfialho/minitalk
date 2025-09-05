/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:40:18 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (0);
	d = dest;
	s = src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			d[n] = s[n];
	return (dest);
}
// #include <string.h>

// int main(void)
// {
// 	char *s1 = ft_calloc(10, 1);
// 	char *s2 = ft_calloc (10, 1);
// 	char s22 = "hellos";
// 	memmove(s1, 0, 4);
// 	//  ft_memmove(0, 0, 4);
// 	// memmove(0, 0, 4);
// 	// memmove(0, 0, 4);
// 	// memmove(0, 0, 4);
// 	// memmove(0, 0, 4);
// 	free(s1);
// 	free(s2);
// }