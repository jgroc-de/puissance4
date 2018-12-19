#include "connect4.h"

int	ft_test_col(t_c4 *board, int col, int line)
{
	int	k;
	int	result;

	k = 1;
	result = board->grid[line][col];
	while (k < 4 && line - k >= 0)
	{
		result += board->grid[line - k++][col];
	}
	return (ft_abs(result) == 4? 1 : 0);
}

int	ft_get_line(t_c4 *board, int col)
{
	int	i;

	i = 0;
	while (i < board->line && board->grid[i][col] != 0)
	{
		i++;
	}
	return (i);
}

int ft_iswin(t_c4 *board, int col)
{
	int	line;

	line = ft_get_line(board, col) - 1;
	if (ft_test_col(board, col, line))
	{
		board->winner = board->grid[line][col];
		return (1);
	}
	return (0);
}
