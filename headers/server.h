/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:20:53 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/13 19:28:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERVER_H
 # define SERVER_H
 
 # include <unistd.h>
 # include <stdlib.h>
 # include <signal.h>
 # include <sys/types.h>
 # include <bits/sigaction.h>
 # include <bits/types/siginfo_t.h>
 
 #include "../superLibft/headers/libft.h"

 typedef struct sigaction t_sa;

 struct s_minitalk {
	int				pid;
	unsigned char	ascii;
	unsigned char	*binary;
 } typedef t_mini;
 
# endif