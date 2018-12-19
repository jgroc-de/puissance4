/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:14:24 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/09/24 18:15:10 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	mergesort!!
*/

void	ft_lst2swap(t_list2 *node1, t_list2 *node2)
{
	void	*content;
	int		size;

	content = node1->content;
	size = node1->content_size;
	node1->content = node2->content;
	node1->content_size = node2->content_size;
	node2->content = content;
	node2->content_size = size;
}
