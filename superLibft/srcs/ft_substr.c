/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:26:45 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = ft_calloc(1, len + 1);
	if (!sub)
		return (0);
	ft_memcpy(sub, s + start, len);
	return (sub);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("%lu\n", ft_strlen(0));
// 	printf("%s\n", ft_substr("tripouille", 0, 0));
// 	printf("%s\n", ft_substr("tripouille", 0, 1));
// 	printf("%s\n", ft_substr("tripouille", 1, 0));
// 	printf("%s\n", ft_substr("tripouille", 1000, 0));
// 	printf("%s\n", ft_substr("tripouille", 0, 1000));
// 	printf("%s\n", ft_substr("tripouille", 110000, 1000));
// 	printf("%s\n", ft_substr("tripouille", 5, 2));
// }