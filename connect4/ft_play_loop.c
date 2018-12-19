#include "connect4.h"

static int	ft_get_play(int max)
{
	int		col;
	char	*str;

	col = 0;
	str = NULL;
	while (col < 1 || col > max)
	{
		ft_printf("Plz enter a number between 1 and %d: ", max);
		get_next_line(0, &str);
		if (!ft_isinteger(str))
			col = 0;
		else
			col = ft_atoi(str);
		ft_strdel(&str);
	}
	return (col - 1 + 3);
}

static int	ft_play(t_c4 *board, int col)
{
	int	i;

	i = 3;
	while (i < board->line && board->grid[i][col] != 0)
		i++;
	if (i != board->line)
	{
		board->grid[i][col] = board->turn;
		return (1);
	}
	else
	{
		ft_printf("column %d is full! Plz choose another one!\n", col + 1 - 3);
		return (0);
	}
}

int	ft_play_loop(t_c4 *board)
{
	int col;

	while (1)
	{
		if (board->turn == 1)
			col = ft_get_play(board->col - 3);
		else
			//ia a mettre la
			col = ft_get_play(board->col - 3);
		if (ft_play(board, col))
			break ;
	}
	return (col);
}
