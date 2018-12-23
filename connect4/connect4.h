/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:25:12 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/12/23 18:01:32 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H
# include "../libft/printf/libprintf.h"
# include <errno.h>
# include <time.h>

# define COL 7
# define LINE 6

typedef struct	s_c4
{
	int 	col;
	int 	line;
	int		player;
	int		winner;
	int		max_turn;
	int		*score;
	int		depth;
	char	**grid;
}				t_c4;

/*
** misc
*/

int		ft_usage(char **av);
int		ft_init(t_c4 *board, char **av);
void	ft_free(t_c4 *board, int i);
void	ft_print(t_c4 *board);

/*
** game loop
*/

int		ft_game_loop(t_c4 *board);
int		ft_play_loop(t_c4 *board, int turn);
int		ft_iswin(t_c4 *board, int col);
int		ft_play(t_c4 *board, int col);
void	ft_remove_play(t_c4 *board, int col);

/*
** ia
*/

int		ft_ia(t_c4 *board, int turn);

#endif
