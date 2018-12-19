#include "connect4.h"

static int	aux_malloc(t_c4 *board)
{
	int	i;

	i = 0;
	if (!(board->grid = (char**)malloc(sizeof(char*) * board->line)))
	{
		ft_printf("%s\n", strerror(errno));
		return (0);
	}
	while (i < board->line)
	{
		if (!(board->grid[i] = ft_strnew_ch(board->col, 0)))
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
	//isinteger count digit, that s all
	if (!ft_isinteger(av[1]) || !ft_isinteger(av[2]))
	{
		return (ft_usage(av));
	}
	board->col = ft_atoi(av[1]);
	board->line = ft_atoi(av[2]);
	if (board->col < COL || board->line < LINE)
	{
		return (ft_usage(av));
	}
	else
	{
		return (aux_malloc(board));
	}
}
