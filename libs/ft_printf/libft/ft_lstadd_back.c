/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:00:37 by sguntepe          #+#    #+#             */
/*   Updated: 2022/11/26 17:00:55 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}

// #include <stdio.h>

// int main()
// {
//     t_list *node1,*node2;

//     node1 = ft_lstnew("42");
//     node2 = ft_lstnew(" Kocaeli");

//     ft_lstadd_back(&node1,node2);

//     printf("%s",(char *)node1->content);
//     printf("%s",(char *)node1->next->content);
// }

// lst structının bağlı olduğu listelerin sonuna gider ve new sructını ekler.