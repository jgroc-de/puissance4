#include "connect4.h"

void	ft_free(t_c4 *board, int i)
{
	while (i >= 0)
	{
		free(board->grid[i--]);
	}
	free(board->grid);
}
