/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 08:58:22 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/11 19:40:16 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*gnl_append(char **left, int fd, char *buffer)
{
	char	*new;
	char	*temp;
	int		i;

	if (!left[fd])
		left[fd] = gnl_strdup("");
	if (!left[fd])
		return (0);
	new = gnl_calloc(gnl_slen(left[fd]) + gnl_slen(buffer) + 1, sizeof(char));
	if (!new)
		return (0);
	i = 0;
	temp = left[fd];
	while (*temp)
		new[i++] = *temp++;
	temp = buffer;
	while (*temp)
		new[i++] = *temp++;
	gnl_free(&left[fd]);
	gnl_free(&buffer);
	left[fd] = new;
	return (new);
}

int	gnl_update_left(char **left, int fd, int start)
{
	char	*new;

	if (!*(left[fd] + start))
		return (gnl_free(&left[fd]), 1);
	new = gnl_strdup(left[fd] + start);
	gnl_free(&left[fd]);
	if (!new)
		return (0);
	left[fd] = new;
	return (1);
}

char	*gnl_get_line(char **left, int fd)
{
	size_t	len;
	char	*line;
	int		i;

	len = gnl_eol(left[fd]);
	if (!len)
		len = gnl_slen(left[fd]);
	line = gnl_calloc(len + 1, sizeof(char));
	if (!line)
		return (gnl_free(&left[fd]), NULL);
	i = len;
	while (i--)
		line[i] = left[fd][i];
	if (!gnl_update_left(left, fd, len))
		return (NULL);
	return (line);
}

char	*gnl_read_to_left(char **left, int fd)
{
	char	*buffer;
	int		b_read;

	while (!gnl_eol(left[fd]))
	{
		buffer = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (gnl_free(&left[fd]), NULL);
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0
			|| (!b_read && !left[fd])
			|| !gnl_append(left, fd, buffer))
			return (gnl_free(&left[fd]), gnl_free(&buffer), NULL);
		if (gnl_eol(left[fd]) || b_read < BUFFER_SIZE || (left[fd] && !b_read))
			return (gnl_get_line(left, fd));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*left[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl_eol(left[fd]))
		return (gnl_get_line(left, fd));
	return (gnl_read_to_left(left, fd));
}
