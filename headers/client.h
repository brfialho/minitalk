/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:20:41 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/13 23:07:18 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLIENT_H
 # define CLIENT_H
 
 # define BYTE_SIZE 8 

 #include <unistd.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <bits/sigaction.h>
 #include <bits/types/siginfo_t.h>

 #include "../superLibft/headers/libft.h"
 
 typedef struct sigaction t_sa;
 
 void sighandler(int signum);
 void send_str(int pid, unsigned char* s);
 void send_bit(int pid, unsigned char* binary);
 
 unsigned char	*itoba(int n);
 unsigned char	*fill_byte(unsigned char *binary);

 
# endif