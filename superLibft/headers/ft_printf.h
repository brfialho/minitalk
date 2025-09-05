/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:34:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 18:13:39 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	pf_putptr(void *p);
int	pf_putstr(char *s);
int	pf_put(char c, void *s);
int	pf_instr(char *s, char c);
int	ft_printf(const char *s, ...);
int	pf_count_digits(int n, int base);
int	pf_put_n(int n, char *base, int len);
int	pf_count_long(unsigned long n, int base);
int	pf_count_unsigned(unsigned int n, int base);
int	pf_put_un(unsigned int n, char *base, int len);
int	pf_put_ul(unsigned long n, char *base, int len);

#endif