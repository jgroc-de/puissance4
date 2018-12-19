#include "connect4.h"

int	ft_usage(char **av)
{
	ft_printf("Usage: %s COL LINE\n\twhere:\n", av[0]);
	ft_printf("\t\tCOL is the number of column >= %d\n", COL);
	ft_printf("\t\tLINE is the number of lines >= %d\n", LINE);
	ft_printf("\t\tex: %s 7 6\n", av[0]);
	return (0);
}
