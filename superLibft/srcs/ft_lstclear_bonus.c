/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:41:40 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*d;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		d = p;
		p = p->next;
		del(d->content);
		free(d);
	}
	*lst = 0;
}

// void ft_delete(void	*v)
// {
// 	free(v);
// }
// #include <stdio.h>
// int	main(void)
// {
// 	// t_list a;
// 	// t_list b;
// 	// t_list c;
// 	// t_list *lst;

// 	// c.next = 0;
// 	// b.next = &c;
// 	// a.next = &b;
// 	// lst = &a;

// 	t_list	*a = malloc(sizeof(t_list));
// 	t_list *b   = malloc(sizeof(t_list));
// 	t_list *c   = malloc(sizeof(t_list));
// 	t_list **lst = malloc(sizeof(t_list *));

// 	*lst = a;
// 	a->next = b;
// 	b->next = c;
// 	c->next = 0;

// 	// printf("%p\n", a);
// 	// printf("%p\n", b);
// 	// printf("%p\n", c);
// 	ft_lstclear(lst, &ft_delete);
// 	// printf("%p\n", a);
// 	// printf("%p\n", b);
// 	// printf("%p\n", c);

// 	// int	*i = malloc (4);
// 	// *i = 4;
// 	// printf("%p %d\n", i, *i);
// 	// free(i);
// 	// printf("%p %d\n", i, *i);

// 	free(lst);
// }