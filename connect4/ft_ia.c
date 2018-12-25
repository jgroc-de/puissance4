/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/24 16:48:12 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void	aux_reset(t_c4 *board)
{
	int i;

	i = 0;
	while (i < COL * COL * COL * COL)
	{
		board->score4[i] = 254;
		i++;
	}
	i = 0;
	while (i < COL * COL * COL)
	{
		board->score3[i] = 254;
		i++;
	}
	i = 0;
	while (i < COL * COL)
	{
		board->score2[i] = 254;
		i++;
	}
	i = 0;
	while (i < COL)
	{
		board->score1[i] = 254;
		i++;
	}
}

void		aux_print_result(t_c4 *board)
{
	int	i;
	int	j;
	int	end;
	int	*save;

	j = 4;
	while (j >= 0)
	{
		ft_printf("-- turn value %d\n", board->depth - j);
		if (j == 0)
		{
			ft_printf("\t\t\t     |%d|\n", board->score0);
		}
		else if (j != 4)
		{
			if (j == 1)
			{
				ft_printf("\t\t\t  ");
				save = board->score1;
			}
			else if (j == 2)
			{
				ft_printf("\t");
				save = board->score2;
			}
			else if (j == 3)
			{
				save = board->score3;
			}
			else if (j == 4)
				save = board->score4;
			end = ft_pow(COL, j);
			i = 0;
			ft_printf("|");
			while (i < end)
			{
				ft_printf("%d|", save[i]);
				if (i % COL == COL - 1 && i != end - 1)
					ft_printf(" * |");
				i++;
			}
		}
		ft_printf("\n\n");
		j--;
	}
}

int			ft_ia(t_c4 *board, int turn)
{
	int col;

	if (turn <= 2)
		return (board->col / 2 + 1);
	board->depth = ft_min(board->hard, board->max_turn - turn + 1);
	aux_reset(board);
	board->player = (board->player == 1) ? -1 : 1;
	col = ft_minimax(board, board->depth);
	board->player = (board->player == 1) ? -1 : 1;
	aux_print_result(board);
	ft_printf(" ** col finale: %d\n", col);
	while (!ft_play(board, col))
	{
		col++;
		if (col > board->col)
			col = 1;
	}
	ft_remove_play(board, col);
	return (col);
}
