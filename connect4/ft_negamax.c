/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/24 16:45:18 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"


void		aux_stock(int *score, int bestscore)
{
	int	i;

	i = 0;
	while (score[i] != 254)
		i++;
	score[i] = bestscore;
}

void		aux_save(t_c4 *board, int turn, int bestscore)
{
	turn = board->depth - turn;
	if (!turn)
		board->score0 = bestscore;
	else if (turn == 1)
		aux_stock(board->score1, bestscore);
	else if (turn == 2)
		aux_stock(board->score2, bestscore);
	else if (turn == 3)
		aux_stock(board->score3, bestscore);
	else if (turn == 4)
		aux_stock(board->score4, bestscore);
}

int			aux_minimax(t_c4 *board, int turn, int *col)
{
	int	bestscore;
	int tmp;
	int	i;

	i = 0;
	*col = 1;
	bestscore = -board->max_turn;
	while (i++ < board->col)
	{
		if (ft_play(board, i))
		{
			tmp = ft_minimax(board, turn - 1);
			if (bestscore < tmp)
			{
				*col = i;
				bestscore = tmp;
			}
			ft_remove_play(board, i);
			if (ft_abs(bestscore) == turn - 2)
				break ;
		}
	}
	return (bestscore);
}

int			ft_minimax(t_c4 *board, int turn)
{
	int	bestscore;
	int col;

	board->player = (board->player == 1) ? -1 : 1;
	if (!turn)
	{
		bestscore = 0;
	}
	else if ((col = ft_can_win(board)))
	{
		bestscore = -board->player * turn;
	}
	else
	{
		bestscore = aux_minimax(board, turn, &col);
	}
	board->player = (board->player == 1) ? -1 : 1;
	aux_save(board, turn, bestscore);
	return (turn == board->depth ? col : bestscore);
}
