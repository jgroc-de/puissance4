/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:11:00 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/05 13:59:04 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **last, void (*del)(void *, size_t))
{
	if ((*last)->next)
		ft_lstdel(&(*last)->next, (*del));
	ft_lstdelone(last, (*del));
}
