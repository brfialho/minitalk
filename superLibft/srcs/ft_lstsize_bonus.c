/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:13:08 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 16:42:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_lstsize(t_list*lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list a;
// 	t_list b;
// 	t_list c;
// 	t_list *lst;
// 	c.next = 0;
// 	b.next = &c;
// 	a.next = &b;
// 	lst = &a;
// 	printf("%d\n", ft_lstsize(0));
// }