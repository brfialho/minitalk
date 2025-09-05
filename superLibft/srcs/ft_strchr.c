/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:40:53 by brfialho          #+#    #+#             */
/*   Updated: 2025/07/29 21:31:42 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if ((char)c == *s++)
			return ((char *)--s);
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	printf("%s\n", ft_strchr("tripouille", 't' + 256));
// 	printf("%s\n", strchr("tripouille", 't' + 256));
// }