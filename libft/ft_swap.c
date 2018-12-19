/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:02:32 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 14:52:26 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(intmax_t *a, intmax_t *b)
{
	intmax_t swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
