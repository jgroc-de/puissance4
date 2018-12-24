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

/*void		aux_stock(int *score, int bestscore)
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
}*/

int			ft_negamax(t_c4 *board, int turn)
{
	int	bestscore;
	int tmp;
	int col;
	int	i;

	if ((tmp = ft_can_win(board)) != 0)
	{
		bestscore = turn;
		if (turn == board->depth)
			col = tmp;
	}
	else if (!turn)
		bestscore = 0;
	else
	{
		i = 1;
		bestscore = -1000;
		while (i <= board->col)
		{
			if (ft_play(board, i))
			{
				board->player = (board->player == 1) ? -1 : 1;
				tmp = -ft_negamax(board, turn - 1);
				if (bestscore == -1000)
					bestscore = tmp;
				else if (board->player == 1)
					bestscore = ft_max(bestscore, tmp);
				else if (board->player == 1)
					bestscore = ft_min(bestscore, tmp);
				if (turn == board->depth && bestscore == tmp)
					col = i;
				board->player = (board->player == 1) ? -1 : 1;
				ft_remove_play(board, i);
			}
			i++;
		}
	}
	//aux_save(board, turn, bestscore);
	if (turn == board->depth)
		return (col);
	else
		return (bestscore);
}
