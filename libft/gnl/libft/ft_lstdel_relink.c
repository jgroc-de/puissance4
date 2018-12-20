/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_relink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:17:45 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/28 15:49:25 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_relink(t_list **del, t_list **node, void (*f)(void*, size_t))
{
	t_list *tmp;

	tmp = *node;
	if (tmp == *del)
		*node = tmp->next;
	else
	{
		while (tmp && tmp != *del && tmp->next != *del)
			tmp = tmp->next;
		if (tmp)
			tmp->next = (*del)->next;
	}
	ft_lstdelone(del, (*f));
	return (*node);
}
