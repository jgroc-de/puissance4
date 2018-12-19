#include "connect4.h"

char	ft_int2symbol(char c)
{
	if (c == 1)
		return ('o');
	else if (c == -1)
		return ('x');
	else
		return (' ');
}

char	ft_empty_line(__attribute__((unused)) char c)
{
	return (' ');
}

char	ft_line_break(__attribute__((unused)) char c)
{
	return ('_');
}

void	ft_line(t_c4 *board, int i, char (*f)(char c))
{
	int	j;

	j = 0;
	ft_printf(" ");
	while (j < board->col)
	{
		if (i == -1)
			ft_printf("____");
		else if (board->grid[i][j] == 1)
			ft_printf("| \e[1;31m%c\e[m ", f(board->grid[i][j]));
		else if (board->grid[i][j] == -1)
			ft_printf("| \e[1;33m%c\e[m ", f(board->grid[i][j]));
		else
			ft_printf("| %c ", f(0));
		j++;
	}
	ft_printf("|\n");
}

void	ft_print(t_c4 *board)
{
	int	i;

	i = board->line - 1;
	ft_line(board, -1, NULL);
	while (i >= 0)
	{
		ft_line(board, i, &ft_empty_line);
		ft_line(board, i, &ft_int2symbol);
		ft_line(board, i, &ft_line_break);
		i--;
	}
}
