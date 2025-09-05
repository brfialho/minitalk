/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:15:54 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	in_str(char c, char*set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const*s1, char const*set)
{
	size_t	len;
	char	*trim;

	while (in_str(*s1, (char *)set))
		s1++;
	len = ft_strlen(s1);
	while (len && in_str(s1[len - 1], (char *)set))
		len--;
	trim = ft_calloc(1, len + 1);
	if (!trim)
		return (0);
	return (ft_memcpy(trim, s1, len));
}
// #include <stdio.h>
// int	main(void)
// {
// 	char * str = ft_strtrim("123212", "1");
// 	printf("%s\n", str);
// 	free(str);
// }