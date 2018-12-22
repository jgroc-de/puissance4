/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:36 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 12:27:30 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int	aux_iswin(int result[7])
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (ft_abs(result[i++]) == 4)
			return (1);
	}
	return (0);
}

static void	aux_reset(int result[7], int content)
{
	int	i;

	i = 0;
	while (i < 7)
		result[i++] = content;
}

int			ft_test(t_c4 *board, int col, int line)
{
	int	k;
	int	result[7];

	k = 1;
	aux_reset(result, board->grid[line][col]);
	while (k < 4)
	{
		result[0] += board->grid[line - k][col];
		result[1] += board->grid[line][col - k];
		result[2] += board->grid[line][col + k];
		result[3] += board->grid[line - k][col - k];
		result[4] += board->grid[line - k][col + k];
		result[5] += board->grid[line + k][col - k];
		result[6] += board->grid[line + k][col + k];
		k++;
	}
	return (aux_iswin(result));
}

int			ft_get_line(t_c4 *board, int col)
{
	int	i;

	i = 0;
	while (i < board->line && board->grid[i + 3][col] != 0)
	{
		i++;
	}
	return (i + 3 - 1);
}

int			ft_iswin(t_c4 *board, int col)
{
	int	line;

	line = ft_get_line(board, col);
	ft_printf("col computer: %d\n", col);
	ft_printf("ligne computer: %d\n", line);
	ft_printf("ligne joueur: %d\n", line - 2);
	if (ft_test(board, col, line))
	{
		board->winner = board->grid[line][col];
		return (1);
	}
	return (0);
}
