/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:39 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 22:13:32 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	ft_play(t_c4 *board, int col)
{
	int	i;
	int	real_col;

	i = 0;
	real_col = col + 2;
	while (i < board->line && board->grid[i + 3][real_col] != 0)
		i++;
	if (i != board->line)
	{
		ft_printf("col: %d\n", i);
		board->grid[i + 3][real_col] = board->player;
		return (1);
	}
	else
	{
		if (board->player == 1)
			ft_printf("column %d is full! Plz choose another one!\n", col);
		return (0);
	}
}
