/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 22:05:13 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void	aux_reset(int *save, t_c4 *board)
{
	int	i;

	i = 0;
	while (i < board->col)
	{
		save[i] = -board->max_turn - 1;
		i++;
	}
}

int			aux_print_result(int *save, t_c4 *board)
{
	int	i;
	int	out;
	int	test;

	i = 0;
	out = 0;
	ft_printf("\n|");
	test = save[0];
	while (i < board->col)
	{
		if (test != save[i])
			out = 1;
		ft_printf(" %d |", save[i]);
		i++;
	}
	return (out);
}

int			ft_ia(t_c4 *board, int turn)
{
	int col;
	int	*save;

	turn = 2 * board->hard;
	if (!(save = (int*)malloc(sizeof(int) * board->col)))
		return (0);
	aux_reset(save, board);
	board->depth = turn;
	col = ft_negamax(board, turn, save);
	ft_printf(" ** col finale: %d\n", col);
	if (col == board->col && !aux_print_result(save, board))
		col = board->col / 2 + 1;
	while (!ft_play(board, col))
	{
		col++;
		if (col > board->col)
			col = 1;
	}
	free(save);
	ft_remove_play(board, col);
	return (col);
}
