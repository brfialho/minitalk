/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:32:22 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/13 15:53:34 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../superLibft/headers/libft.h"
#include "../headers/client.h"

char	*fill_byte(char *binary)
{
	int		i;
	int		len;
	char	*new;

	if (!binary)
		return (0);
	len = ft_strlen(binary);
	if (len == BYTE_SIZE)
		return (binary);
	new = ft_calloc(BYTE_SIZE + 1, sizeof(char));
	if (!new)
		return (ft_free(&binary), NULL);
	i = 0;
	while (i < BYTE_SIZE)
	{
		if (i < BYTE_SIZE - len)
			new[i++] = '0';
		else
			new[i++] = *binary++;
	}
	free(binary - len);
	return (new);
}
