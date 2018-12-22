/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 13:38:29 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int ft_tab_min(int *value, int col)
{
	int	i;
	int	min;

	i = 1;
	min = value[0];
	while (i < col)
	{
		if (value[i] < min)
			min = value[i];
		i++;
	}
	return (min);
}

int ft_tab_max(int *value, int col)
{
	int	i;
	int	max;

	i = 1;
	max = value[0];
	while (i < col)
	{
		if (value[i] > max)
			max = value[i];
		i++;
	}
	return (max);
}

int	ft_ia(t_c4 *board)
{
	int col;
	int	i;

	i = 0;
	while (i < board->col)
	{
		board->score[i] = ft_minimax(board, i, board->depth);
		i++;
	}
	col = ft_tab_min(board->score, board->col);
	return (board->col / 2);
}
