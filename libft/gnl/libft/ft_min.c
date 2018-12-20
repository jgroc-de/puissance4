/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:30:29 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/11 17:09:58 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int *tab, int len)
{
	int		min;
	int		i;

	i = 0;
	if (len == 0)
	{
		ft_putstr("ERROR ft_min");
		return (0);
	}
	min = tab[0];
	while (i < len)
	{
		if (min > tab[i])
			min = tab[i];
		i++;
	}
	return (min);
}
