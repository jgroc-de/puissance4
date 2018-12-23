/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 17:36:35 by jgroc-de         ###   ########.fr       */
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

int	ft_minimax(t_c4 *board, int depth)
{
	int	i;
	int	score;

	board->player = (board->player == 1) ? -1 : 1;
	if ((i = ft_can_win(board)) != 0)
	{
		//ft_printf("** player %dwin \n", board->player);
		score = depth + 1;
	}
	else if (depth == board->depth)
		score = 0;
	else
	{
		score = -100;
		i = 1;
		while (i <= board->col)
		{
			if (ft_play(board, i))
			{
				score = ft_max(score, -ft_minimax(board, depth + 1));
				ft_remove_play(board, i);
			}
			i++;
		}
	}
	board->player = (board->player == 1) ? -1 : 1;
	return (score);
}

int	ft_ia(t_c4 *board, int turn)
{
	int col;
	int score;
	int	tmp;
	int i;

	if ((i = ft_can_win(board)) != 0)
		return (i);
	board->depth = turn;
	board->depth = 3;
	ft_printf(" |");
	i = 1;
	col = 1;
	score = -100;
	while (i <= board->col)
	{
		if (ft_play(board, i))
		{
			tmp = ft_minimax(board, 0);
			ft_printf(" %d |", tmp);
			if (score < tmp)
			{
				col = i;
				score = tmp;
			}
			ft_remove_play(board, i);
			if (score == 1)
				break ;
		}
		i++;
	}
	while (!ft_play(board, col))
		col++;
	ft_remove_play(board, col);
	ft_printf("final score %d\n", score);
	ft_printf(" ** col finale: %d\n", col);
	return (col);
}
