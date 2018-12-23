/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:48 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 20:32:31 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	main(int ac, char **av)
{
	t_c4	board;

	srand(time(NULL));
	if (ac != 3)
		ft_usage(av);
	else
	{
		if (!ft_init(&board, av))
			return (EXIT_FAILURE);
		ft_game_loop(&board);
		ft_free(&board, board.line + 6);
	}
	return (EXIT_SUCCESS);
}
