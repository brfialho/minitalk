/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/05 18:11:31 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/server.h"

int main(int argc, char **argv)
{
	printf("%d\n", get_int());

	(void)argc;
	(void)argv;
}