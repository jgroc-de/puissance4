/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:35:13 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/11 18:17:31 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int n)
{
	int i;

	i = 0;
	while (i * i < n && i <= 46340)
		i++;
	return (i);
}
