/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:28 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 16:02:22 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void	ft_print_winner(t_c4 *board)
{
	ft_print(board);
	ft_putstr("\n\t\t*** ");
	if (!board->winner)
		ft_printf("Your strengh are equals, unbelievable!");
	else
		ft_printf("%s won!", board->winner == 1 ? "you" : "computer");
	ft_putstr(" ***\n");
}

int			ft_game_loop(t_c4 *board)
{
	int	turn;
	int col;

	turn = board->line * board->col;
	while (turn--)
	{
		board->depth = ft_min(4, turn);
		ft_print(board);
		ft_printf("\n\n\t*** It's %s turn to play! ***\n",
			board->player == 1 ? "your" : "computer's");
		if ((col = ft_play_loop(board, turn)) == -1)
			return (0);
		if (ft_iswin(board, col))
			break ;
		board->player = board->player == 1 ? -1 : 1;
	}
	ft_print_winner(board);
	return (1);
}
