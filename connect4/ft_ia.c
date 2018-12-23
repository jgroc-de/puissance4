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

int	ft_minimax(t_c4 *board, int depth)
{
	int	i;
	int	score;
	int	tmp;

	i = 1;
	score = 0;
	if (depth <= 0)
		i = board->col + 1;
	while (i <= board->col)
	{
		ft_printf("depth: %d\n", depth);
		if (ft_play(board, i))
		{
			if (!ft_iswin(board, i) && turn != 0)
			{
				board->player = (board->player == 1) ? -1 : 1;
				tmp = ft_minimax(board, depth - 1);
				board->player = (board->player == 1) ? -1 : 1;
				if (score > tmp)
				{
					score = tmp;
				}
			}
			else
			{
				score = depth * 2 * board->player;
				ft_remove_play(board, i);
				return (board->player * turn);
			}
		}
		j++;
	}
	return (score);
}

int	ft_ia(t_c4 *board, int turn)
{
	int col;
	int	i;
	int	score;
	int	tmp;

	i = 1;
	score = -1;
	col = 1;
	while (i <= board->col)
	{
		tmp = ft_minimax(board, turn = 2);
		if (score > tmp)
		{
			score = tmp;
			col = i;
		}
		ft_printf("i: %d\n", i);
		i++;
	}
	ft_printf("col: %d\n", col);
	if (col == 1)
	{
		while (!ft_play(board, col))
		{
			col++;
		}
		ft_remove_play(board, col);
	}
	ft_printf("col: %d\n", col);
	return (col);
}
