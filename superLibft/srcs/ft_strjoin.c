/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:16:05 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*join;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = ft_calloc(1, len + 1);
	if (!join)
		return (0);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	return (join - len);
}

// int	main(void)
// {
// 	ft_putstr_fd(ft_strjoin("asdui", "bbb"), 1);
// }