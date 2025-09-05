/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:11:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/05 18:11:18 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "headers/client.h"

int main(int argc, char **argv)
{
	printf("%d\n", get_int());

	(void)argc;
	(void)argv;
}