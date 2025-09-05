/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:14:15 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 17:15:54 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

void	*gnl_calloc(size_t nmemb, size_t size);

char	*gnl_append(char **left, int fd, char *buffer);
char	*gnl_read_to_left(char **left, int fd);
char	*gnl_get_line(char **left, int fd);
char	*get_next_line(int fd);
char	*gnl_strdup(char	*s);

size_t	gnl_strlen(char *s);

int		gnl_eol(char *s);
int		gnl_free(char **s);
int		gnl_update_left(char **left, int fd, int start);

#endif