/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:48:44 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 18:05:53 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	if (size && nmemb > ((size_t) -1) / size)
		return (0);
	array = malloc(nmemb * size);
	if (!array)
		return (0);
	i = 0;
	while (i < nmemb * size)
		((char *)array)[i++] = 0;
	return (array);
}

size_t	gnl_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

int	gnl_free(char **s)
{
	if (!s || !*s)
		return (0);
	free(*s);
	*s = 0;
	return (0);
}

int	gnl_eol(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		if (s[len++] == '\n')
			return (len);
	return (0);
}

char	*gnl_strdup(char	*s)
{
	char	*new;
	int		i;

	new = gnl_calloc(gnl_strlen(s) + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	return (new);
}
