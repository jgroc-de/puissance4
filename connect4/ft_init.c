#include "connect4.h"

static int	aux_malloc(t_c4 *board)
{
	int	i;

	if (!(board->grid = (char**)malloc(sizeof(char*) * (board->line + 3))))
	{
		ft_printf("%s\n", strerror(errno));
		return (0);
	}
	i = 0;
	while (i < board->line + 3)
	{
		if (!(board->grid[i] = ft_strnew_ch(board->col + 3, 0)))
		{
			ft_printf("%s\n", strerror(errno));
			ft_free(board, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_init(t_c4 *board, char **av)
{
	//isinteger counts digit, that s all
	if (!ft_isinteger(av[1]) || !ft_isinteger(av[2]))
	{
		return (ft_usage(av));
	}
	board->col = ft_atoi(av[1]) + 3;
	board->line = ft_atoi(av[2]) + 3;
	if (board->col - 3 < COL || board->line - 3 < LINE)
	{
		return (ft_usage(av));
	}
	else
	{
		return (aux_malloc(board));
	}
	board->winner = 0;
	srand(time(NULL));
	board->turn = rand() > (RAND_MAX / 2) ? 1 : -1;
}
