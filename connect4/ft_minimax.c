/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/28 14:51:18 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void		aux_stock(int *score, int bestscore, int col)
{
	score[col] = bestscore;
}

void		aux_save(t_c4 *board, int turn, int bestscore, int col)
{
	if (!turn)
		board->score0 = bestscore;
	else if (turn == 1)
		aux_stock(board->score1, bestscore, col);
	else if (turn == 2)
		aux_stock(board->score2, bestscore, col);
	else if (turn == 3)
		aux_stock(board->score3, bestscore, col);
	else if (turn == 4)
		aux_stock(board->score4, bestscore, col);
}

/*
** IA = 1
** HUMAN = -1
*/

int			aux_minimax(t_c4 *board, int turn, int *col)
{
	int	bestscore;
	int tmp;
	int	i;
	int	j;
	int k;

	j = 0;
	i = (board->col / 2) + 1;
	*col = i;
	(void)best;
	bestscore = -board->player * board->max_turn;
	while (i + j <= board->col && i + j > 0)
	{
		k = i + j;
		if (bestscore == board->player * turn)
			break ;
		if (ft_play(board, k))
		{
			if (ft_iswin(board, k))
			{
				bestscore = board->player * turn;
				*col = k;
			}
			else
			{
				tmp = ft_minimax(board, turn + 1);
				if (board->player == IA)
					bestscore = ft_max(bestscore, tmp);
				else
					bestscore = ft_min(bestscore, tmp);
				if (bestscore == tmp)
					*col = k;
			}
			ft_remove_play(board, k);
		}
		j = j > 0 ? -j : -j + 1;
	}
	return (bestscore);
}

int			ft_minimax(t_c4 *board, int turn)
{
	int	bestscore;
	int col;

	col = 1;
	board->player = (board->player == IA) ? HUMAN : IA;
	if (turn > board->depth)
	{
		bestscore = board->player * turn;
	}
	else
	{
		bestscore = aux_minimax(board, turn, &col);
	}
	board->player = (board->player == IA) ? HUMAN : IA;
	aux_save(board, turn, bestscore, col - 1);
	return (turn == 0 ? col : bestscore);
}
