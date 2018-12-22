/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:39 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 13:37:51 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int	ft_get_play(int max)
{
	int		col;
	char	*str;

	col = 0;
	str = NULL;
	while (col < 1 || col > max)
	{
		ft_printf("Plz enter a number between 1 and %d: ", max);
		get_next_line(0, &str);
		if (!ft_isinteger(str))
			col = 0;
		else
			col = ft_atoi(str);
		ft_strdel(&str);
	}
	return (col);
}

static int	ft_play(t_c4 *board, int col)
{
	int	i;
	int	real_col;

	i = 0;
	real_col = col - 1 + 3;
	while (i < board->line && board->grid[i + 3][real_col] != 0)
		i++;
	if (i != board->line)
	{
		board->grid[i + 3][real_col] = board->turn;
		return (1);
	}
	else
	{
		ft_printf("column %d is full! Plz choose another one!\n", col);
		return (0);
	}
}

int			ft_play_loop(t_c4 *board)
{
	int col;

	while (1)
	{
		if (board->turn == 1)
			col = ft_get_play(board->col);
		else
			col = ft_get_play(board->col);
			//col = ft_ia(board);
		if (ft_play(board, col))
			break ;
	}
	ft_printf("col jouée: %d\n", col);
	return (col + 2);
}
