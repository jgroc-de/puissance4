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
	int		depth;
	int		turn;
	int		winner;
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
int		ft_play_loop(t_c4 *board);
int		ft_iswin(t_c4 *board, int col);

#endif
