/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:09:50 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/05 11:54:07 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *prev;
	t_list *head;

	head = NULL;
	if (lst)
	{
		head = ft_lstnew(lst->content, lst->content_size);
		if (head == NULL)
			return (NULL);
		head = (*f)(head);
		lst = lst->next;
		prev = head;
		while (lst)
		{
			new = ft_lstnew(lst->content, lst->content_size);
			if (new == NULL)
				return (NULL);
			new = (*f)(new);
			prev->next = new;
			lst = lst->next;
			prev = new;
		}
	}
	return (head);
}
