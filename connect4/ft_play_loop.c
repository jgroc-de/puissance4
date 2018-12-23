/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:39 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 20:53:40 by jgroc-de         ###   ########.fr       */
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
		if (get_next_line(0, &str) == -1)
		{
			ft_putstr(strerror(errno));
			return (-1);
		}
		if (!ft_isinteger(str))
			col = 0;
		else
			col = ft_atoi(str);
		ft_strdel(&str);
	}
	return (col);
}

int			ft_play_loop(t_c4 *board, int turn)
{
	int col;

	while (1)
	{
		if (board->player == 1)
			if ((col = ft_get_play(board->col)) == -1)
				return (-1);
		else
		{
			if ((col = ft_ia(board, turn)) == 0)
				return (-1);
		}
		if (ft_play(board, col))
			break ;
	}
	return (col);
}
