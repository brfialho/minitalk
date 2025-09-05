/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:04:41 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 16:44:27 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n || (!*s1 && !*s2))
		return (0);
	while ((*s1 || *s2) && n-- && *s1++ == *s2++)
		;
	return ((unsigned char)*--s1 - (unsigned char)*--s2);
}
//hello/0
//helloa/0
//n = 100
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char *s1 = malloc(1);
// 	char *s2 = malloc(1);

// 	s1[0] = 0;
// 	s2[0] = 0;
// 	// printf("%d\n", ft_strncmp(s1, s2, 10));
// 	//printf("%d\n", ft_strncmp(NULL, NULL, 10));
// 	// printf("%d\n", ft_strncmp("", "", 10));
// 	// printf("%d\n", ft_strncmp(0, 0, 10));

// 	// printf("%d\n", strncmp(s1, s2, 10));
// 	//printf("%d\n", strncmp(NULL, NULL, 10));
// 	// printf("%d\n", strncmp("", "", 10));
// 	// printf("%d\n", strncmp(0, 0, 10));
// }

// #include <stdio.h>
// int main(void)
// {
// 	int	*a = malloc(8);
// 	char b[] = {46, -121, -38, 13};
// 	a[0] = 232425262;
// 	// a[1] = 299925262;

// 	printf("%d\n", a[0]);
// 	printf("%d\n", ((char *)a)[0]);
// 	printf("%d\n", ((char *)a)[1]);
// 	printf("%d\n", ((char *)a)[2]);
// 	printf("%d\n", ((char *)a)[3]);

// 	printf("%d\n", ((int *)b)[0]);
// }

// a[0] = 232425262;
// [][][][] | [][][][]
// [] | [] | [] | [] | [] | [] | [] | []