/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:03:53 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 22:36:22 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	ft_minimax(t_c4 *board, int turn, int i)
{
	int j;
	int tmp;

	j = 1;
	while (j < board->col)
	{
		if (ft_play(board, i))
		{
			if (!ft_iswin(board, i + 2) && turn != 0)
			{
				board->player = turn % 2 == 0 ? -1 : 1;
				tmp = ft_minimax(board, turn - 1, j);
				board->player = turn % 2 == 0 ? -1 : 1;
				ft_remove_play(board, i);
				return (tmp);
			}
			else
			{
				ft_remove_play(board, i);
				return (board->player * turn);
			}
		}
	j++;
	}
	return (0);
}

int	ft_ia(t_c4 *board, int turn)
{
	int col[7];
	int tmp;
	int i;
	int colonne;

	i = 0;
	while (i < 7)
	{
		col[i] = ft_minimax(board, turn, i + 1);
		i++;
	}
	i = 0;
	tmp = col[i];
	colonne = i + 1;
	i = 1;
	while (i < 7)
	{
		if (tmp < col[i])
		{
			tmp = col[i];
			colonne = i + 1;
		}
		i++;
	}
	return (colonne);
}
