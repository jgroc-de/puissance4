#include "connect4.h"

static void	ft_print_winner(t_c4 *board)
{
	ft_print(board);
	ft_putstr("\n\t\t*** ");
	if (!board->winner)
		ft_printf("Your strengh are equals, unbelievable!");
	else
		ft_printf("%s won!", board->winner == 1? "you" : "computer");
	ft_putstr(" ***\n");
}

int 		ft_game_loop(t_c4 *board)
{
	int	turn;

	turn = board->line * board->col;
	board->winner = 0;
	srand(time(NULL));
	board->turn = rand() > (RAND_MAX / 2) ? 1 : -1;
	while (turn--)
	{
		ft_print(board);
		ft_printf("\n\n\t*** It's %s turn to play! ***\n",
			board->turn == 1 ? "your" : "computer's");
		if (ft_iswin(board, ft_play_loop(board)))
		//ou tableau remplit!
			break;
		board->turn = board->turn == 1 ? -1 : 1;
	}
	ft_print_winner(board);
	return (1);
}
