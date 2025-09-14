/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:20:53 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/14 19:54:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define BYTE_SIZE 8

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <bits/sigaction.h>
# include <bits/types/siginfo_t.h>

# include "../superLibft/headers/libft.h"

typedef struct sigaction	t_sa;
typedef struct s_minitalk
{
	int		ascii;
	char	*binary;
}				t_mini;

extern t_mini				g_mini;

void	mini_init(void);
void	recreate_binary(int b);
void	listen_for_string(void);
void	get_binary(int signo, siginfo_t *info, void *context);

#endif