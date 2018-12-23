/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:36 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 22:32:07 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int	aux_iswin(int result[7])
{
	int	i;

	i = 0;
	while (i < 13)
	{
		if (ft_abs(result[i++]) == 4)
			return (1);
	}
	return (0);
}

static void	aux_reset(int result[7])
{
	int	i;

	i = 0;
	while (i < 13)
		result[i++] = 0;
}

int			ft_test(t_c4 *board, int col, int line)
{
	int	k;
	int	result[13];

	k = 0;
	aux_reset(result);
	while (k < 4)
	{
		result[0] += board->grid[line - k][col];
		result[1] += board->grid[line][col - k];
		result[2] += board->grid[line][col - 2 + k];
		result[3] += board->grid[line][col - 1 + k];
		result[4] += board->grid[line][col + k];
		result[5] += board->grid[line - k][col - k];
		result[6] += board->grid[line - 2 + k][col - 2 + k];
		result[7] += board->grid[line - 1 + k][col - 1 + k];
		result[8] += board->grid[line + k][col + k];
		result[9] += board->grid[line - k][col + k];
		result[10] += board->grid[line - 2 + k][col + 2 - k];
		result[11] += board->grid[line - 1 + k][col + 1 - k];
		result[12] += board->grid[line + k][col - k];
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
	return (i + 3);
}

int			ft_iswin(t_c4 *board, int col)
{
	int	line;

	col += 2;
	line = ft_get_line(board, col);
	ft_printf("col computer: %d\n", col);
	ft_printf("ligne computer: %d\n", line - 1);
	ft_printf("ligne joueur: %d\n", line - 3);
	if (ft_test(board, col, line - 1))
	{
		board->winner = board->grid[line - 1][col];
		return (1);
	}
	return (0);
}
