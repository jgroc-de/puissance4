/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 18:11:41 by jgroc-de         ###   ########.fr       */
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

	if (turn == board->max_turn || turn - board->depth >= board->depth)
		bestscore = 0;
	else if ((i = ft_can_win(board)) != 0)
	{
		ft_printf("** player %dwin \n", board->player);
		bestscore = board->max_turn - turn + 1;
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
				bestscore = ft_max(bestscore, -ft_negamax(board, turn + 1));
				board->player = (board->player == 1) ? -1 : 1;
				ft_remove_play(board, i);
			}
			i++;
		}
	}
	return (bestscore);
}

int	ft_ia(t_c4 *board, int turn)
{
	int col;
	int score;
	int	tmp;
	int i;

	score = -board->max_turn;
	i = 1;
	col = 1;
	board->depth = turn;
	while (i <= board->col)
	{
		tmp = ft_negamax(board, turn);
		ft_printf(" %d |", tmp);
		if (score < tmp)
		{
			col = i;
			score = tmp;
		}
		if (score == 1)
			break ;
		i++;
	}
	while (!ft_play(board, col))
		col++;
	ft_remove_play(board, col);
	ft_printf("final score %d\n", score);
	ft_printf(" ** col finale: %d\n", col);
	return (col);
}
