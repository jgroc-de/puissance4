/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:38:48 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/05 13:36:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	mem = (char*)malloc(sizeof(*mem) * size);
	if (mem)
	{
		i = 0;
		while (i < size)
		{
			mem[i] = '\0';
			i++;
		}
	}
	return ((void*)mem);
}
