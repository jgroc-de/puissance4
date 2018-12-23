/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 20:03:03 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	aux_negamax(t_c4 *board, int turn, int *col, int *save)
{
	int	bestscore;
	int	tmp;
	int	i;

	bestscore = -board->max_turn;
	i = 1;
	while (i <= board->col)
	{
		if (ft_play(board, i))
		{
			board->player = (board->player == 1) ? -1 : 1;
			bestscore = ft_max(bestscore, tmp = -ft_negamax(board, turn - 1, save));
			if (turn == board->depth && bestscore == tmp)
				*col = i;
			board->player = (board->player == 1) ? -1 : 1;
			ft_remove_play(board, i);
		}
		if (turn == board->depth)
			save[i - 1] = bestscore;
		i++;
	}
	return (bestscore);
}

int	ft_negamax(t_c4 *board, int turn, int *save)
{
	int	bestscore;
	int tmp;
	int col;

	col = board->col / 2 + 1;
	if (!turn)
		bestscore = 0;
	else if ((tmp = ft_can_win(board)) != 0)
	{
		if (turn == board->depth)
		{
			col = tmp;
			save[0] = -200;
		}
		else
			bestscore = turn;
	}
	else
	{
		bestscore = aux_negamax(board, turn, &col, save);
	}
	if (turn == board->depth)
		return (col);
	else
		return (bestscore);
}
