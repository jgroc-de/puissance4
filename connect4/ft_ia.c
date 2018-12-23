/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 18:59:15 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int ft_can_win(t_c4 *board)
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

int	ft_negamax(t_c4 *board, int turn)
{
	int	i;
	int	bestscore;
	int tmp;
	int col;

	if (!turn)
		bestscore = 0;
	else if ((i = ft_can_win(board)) != 0)
	{
		if (turn == board->depth)
		{
			ft_printf("** player %d win \n", board->player);
			col = i;
		}
		else
			bestscore = turn;
	}
	else
	{
		bestscore = -board->max_turn;
		i = 1;
		while (i <= board->col)
		{
			if (ft_play(board, i))
			{
				board->player = (board->player == 1) ? -1 : 1;
				bestscore = ft_max(bestscore, tmp = -ft_negamax(board, turn - 1));
				if (turn == board->depth)
				{
					if (bestscore == tmp)
						col = i;
					ft_printf(" %d |", tmp);
				}
			//	ft_printf("tmp %d", tmp);
				board->player = (board->player == 1) ? -1 : 1;
				ft_remove_play(board, i);
			}
			i++;
		}
	}
	if (turn == board->depth)
		return (col);
	else
		return (bestscore);
}

int	ft_ia(t_c4 *board, int turn)
{
	int col;

	turn = 8;
	board->depth = turn;
	col = ft_negamax(board, turn);
	ft_printf("|");
	while (!ft_play(board, col))
		col++;
	ft_remove_play(board, col);
	ft_printf(" ** col finale: %d\n", col);
	return (col);
}
