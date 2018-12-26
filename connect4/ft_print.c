/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:42 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/24 15:10:52 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

char	ft_int2symbol(char c)
{
	if (c == HUMAN)
		return ('o');
	else if (c == IA)
		return ('x');
	else
		return (' ');
}

char	ft_empty_line(__attribute__((unused)) char c)
{
	return (' ');
}

char	ft_line_break(__attribute__((unused)) char c)
{
	return ('_');
}

void	ft_line(t_c4 *board, int i, char (*f)(char c))
{
	int	j;

	j = 3;
	i += 3;
	ft_printf(" ");
	while (j - 3 < board->col)
	{
		if (i == 2)
			ft_printf("____");
		else if (i == 1)
			ft_printf("  %d ", j - 2);
		else if (board->grid[i][j] == HUMAN)
			ft_printf("| \e[1;31m%c\e[m ", f(board->grid[i][j]));
		else if (board->grid[i][j] == IA)
			ft_printf("| \e[1;33m%c\e[m ", f(board->grid[i][j]));
		else
			ft_printf("| %c ", f(0));
		j++;
	}
	ft_printf("|\n");
}

void	ft_print(t_c4 *board)
{
	int	i;

	i = board->line - 1;
	ft_printf("\n");
	ft_line(board, -1, NULL);
	while (i >= 0)
	{
		ft_line(board, i, &ft_empty_line);
		ft_line(board, i, &ft_int2symbol);
		ft_line(board, i, &ft_line_break);
		i--;
	}
	ft_line(board, -2, NULL);
	ft_printf("human player: \e[1;31mo\e[m\n");
	ft_printf("computer player: \e[1;33mx\e[m\n");
}
