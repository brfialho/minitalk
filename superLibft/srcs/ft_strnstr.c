/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:57:48 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_size;
	char	*b;

	b = (char *)big;
	if (!*little)
		return (b);
	i = 0;
	little_size = ft_strlen(little) - 1;
	while (*b && len--)
	{
		while (b[i] == little[i] && i <= len)
			if (i++ == little_size)
				return (b);
		i = 0;
		b++;
	}
	return (0);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 		printf("%s\n", ft_strnstr("aaabcabcd", "cd", 8));
// 	printf("%s\n", strnstr("aaabcabcd", "cd", 8));
// 		printf("%s\n", ft_strnstr("oABCooo", "ABC", 4));
// 	printf("%s\n", strnstr("oABCooo", "ABC", 4));
// 		printf("%s\n", ft_strnstr("oABCooo", "ABC", 2));
// 	printf("%s\n", strnstr("oABCooo", "ABC", 2));
// 		printf("%s\n", ft_strnstr("", "", 3));
// 	printf("%s\n", strnstr("", "", 3));
// 		printf("%s\n", ft_strnstr("oABCooo", "", 3));
// 	printf("%s\n", strnstr("oABCooo", "", 3));
// 		printf("%s\n", ft_strnstr("oABXXXXXXXXABAoABCoo", "ABC", 30));
// 	printf("%s\n", strnstr("oABXXXXXXXXABAoABCoo", "ABC", 30));
// 		printf("%s\n", ft_strnstr("oABCooo", "ABC", 3));
// 	printf("%s\n", strnstr("oABCooo", "ABC", 3));
// }