/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:39 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/22 15:54:13 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	ft_remove_play(t_c4 *board, int col)
{
	int	i;
	int	real_col;

	i = 0;
	real_col = col - 1 + 3;
	while (i < board->line && board->grid[i + 3][real_col] != 0)
		i++;
	i--;
	board->grid[i + 3][real_col] = 0;
}
