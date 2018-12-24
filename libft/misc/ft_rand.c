/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 12:59:13 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/24 13:06:23 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** add srand(time(NULL)); only one time somewhere
*/
//attention, fonction de la libc

int	ft_rand(int a, int b)
{
	return (rand() % (b - a) + a);
}
