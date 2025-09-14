/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:20:53 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/13 23:08:42 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERVER_H
 # define SERVER_H
 
 # define BYTE_SIZE 8
 
 # include <unistd.h>
 # include <stdlib.h>
 # include <signal.h>
 # include <sys/types.h>
 # include <bits/sigaction.h>
 # include <bits/types/siginfo_t.h>
 
 #include "../superLibft/headers/libft.h"

 typedef struct sigaction t_sa;

 struct s_minitalk {
	int		pid;
	int		ascii;
	char	*binary;
 } typedef t_mini;

 void	mini_init(void);
 void	recreate_binary(int b);
 void	listen_for_string(void);
 void 	get_binary(int signo, siginfo_t *info, void *context);
 
# endif