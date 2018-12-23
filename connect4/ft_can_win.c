/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 20:13:35 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	ft_can_win(t_c4 *board)
{
	int	i;

	i = 1;
	while (i <= board->col)
	{
		if (ft_play(board, i))
		{
			if (ft_iswin(board, i))
			{
				ft_remove_play(board, i);
				return (i);
			}
			ft_remove_play(board, i);
		}
		i++;
	}
	return (0);
}
