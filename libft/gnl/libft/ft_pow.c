/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:19:55 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/11/11 18:50:07 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, int power)
{
	int i;
	int res;

	res = nb;
	i = 1;
	while (i++ < power)
		res = res * nb;
	if (power <= 0)
		return (1);
	return (res);
}
