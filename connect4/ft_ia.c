/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 16:18:52 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	ft_ia(t_c4 *board, int turn)
{
	int col;
	int	i;
	int	score;
	int	tmp;

	i = 0;
	score = board->player * (turn + 1);
	col = 0;
	while (i < board->col)
	{
		if (ft_play(board, i))
		{
			if (!ft_iswin(board, i))
			{
				//tmp = ft_minimax(board, depth);
				tmp = score - 1;
				if (ft_min(score, tmp) == tmp)
				{
					score = tmp;
					col = i;
				}
			}
			else
			{
				col = i;
				i = board->col;
			}
			ft_remove_play(board, i);	
		}
		i++;
	}
	return (col);
}
