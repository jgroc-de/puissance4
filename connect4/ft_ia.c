/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 23:38:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	ft_minimax(t_c4 *board, int depth, int first)
{
	int	i;
	int	score;
	int	tmp;
	int col;

	i = 1;
	col = 1;
	score = 0;
	if (depth <= 0)
		return (0);
	while (i <= board->col)
	{
		if (ft_play(board, i))
		{
			if (!ft_iswin(board, i))
			{
				board->player = (board->player == 1) ? -1 : 1;
				tmp = ft_minimax(board, depth - 1, 0);
				if (first)
					ft_printf("| %d ", tmp);
				board->player = (board->player == 1) ? -1 : 1;
				if (ft_abs(score) < ft_abs(tmp))
				{
					score = tmp;
					col = i;
				}
			}
			else
			{
				score = depth * 2 * board->player;
				if (first)
					ft_printf(" %d |", score);
				ft_remove_play(board, i);
				return (first == 1 ? i : score);
			}
			ft_remove_play(board, i);
		}
		i++;
	}
	return (first == 1 ? col : score);
}

int	ft_ia(t_c4 *board, int turn)
{
	int col;

	ft_printf(" ");
	col = ft_minimax(board, turn = 3, 1);
	while (!ft_play(board, col))
	{
		col++;
	}
	ft_remove_play(board, col);
	ft_printf("col finale: %d\n", col);
	return (col);
}
