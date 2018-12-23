/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:33 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 20:36:51 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int	aux_malloc(t_c4 *board)
{
	int	i;

	if (!(board->score = (int*)malloc(sizeof(int) * board->col)))
	{
		ft_printf("%s\n", strerror(errno));
		return (0);
	}
	if (!(board->grid = (char**)malloc(sizeof(char*) * (board->line + 6))))
	{
		ft_printf("%s\n", strerror(errno));
		free(board->score);
		return (0);
	}
	i = 0;
	while (i < board->line + 6)
	{
		if (!(board->grid[i] = ft_strnew_ch(board->col + 6, 0)))
		{
			ft_printf("%s\n", strerror(errno));
			ft_free(board, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	rand_a_b(int a, int b)
{
	return (rand() % (b - a) + a);
}

int			ft_init(t_c4 *board, char **av)
{
	if (!ft_isinteger(av[1]) || !ft_isinteger(av[2]))
	{
		return (ft_usage(av));
	}
	board->col = ft_atoi(av[1]);
	board->line = ft_atoi(av[2]);
	if (board->line % 2 != 0 && board->col % 2 != 0)
		return (ft_usage(av));
	board->winner = 0;
	board->player = (rand_a_b(0, 2) > 0) ? 1 : -1;
	ft_printf("board line %d\n", board->line);
	ft_printf("board col %d\n", board->col);
	if (board->col < COL || board->line < LINE)
	{
		return (ft_usage(av));
	}
	else
	{
		return (aux_malloc(board));
	}
}
