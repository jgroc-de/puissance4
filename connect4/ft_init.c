/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:33 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/27 16:27:47 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int	ft_get_hardness(int max)
{
	int		hard;
	char	*str;
	int		tmp;

	hard = 0;
	str = NULL;
	while (hard < 1 || hard > max)
	{
		ft_printf("Choose your difficulty\n");
		ft_printf("Plz enter a number between 1 and %d: ", max);
		if ((tmp = get_next_line(0, &str)) == -1)
		{
			ft_putstr(strerror(errno));
			return (-1);
		}
		if (!ft_isinteger(str))
			hard = 0;
		else
			hard = ft_atoi(str);
		if (tmp == 1)
			ft_strdel(&str);
	}
	return (hard);
}

static int	aux_malloc(t_c4 *board)
{
	int	i;

	if (!(board->grid = (char**)malloc(sizeof(char*) * (board->line + 6))))
	{
		ft_printf("%s\n", strerror(errno));
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

int			ft_init(t_c4 *board, char **av)
{
	if (!ft_isinteger(av[1]) || !ft_isinteger(av[2]))
		return (ft_usage(av));
	board->col = ft_atoi(av[1]);
	board->line = ft_atoi(av[2]);
	if (board->line % 2 != 0 && board->col % 2 != 0)
		return (ft_usage(av));
	board->winner = 0;
	board->player = (ft_rand(0, 2) > 0) ? IA : HUMAN;
	if (board->col < COL || board->line < LINE)
		return (ft_usage(av));
	else
	{
		if ((board->hard = ft_get_hardness(15)) == -1)
			return (0);
		return (aux_malloc(board));
	}
}
