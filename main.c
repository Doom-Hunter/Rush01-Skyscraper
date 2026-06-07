/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:31:41 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 15:31:41 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(char c);
int	ft_print(char *str);
void	ft_print_board(unsigned short **board, int board_size);
int	ft_parse_clues(char *str, int *clues, int size);
int	ft_solve_skyscraper(unsigned short **board, int *clues, int size);

int	main(int argc, char **argv)
{
	int 			board_size;
	int 			x;
	int 			y;
	int				*clues;
	unsigned short	**board;
	
	board_size = 4;
	clues = malloc(sizeof(int *) * 4 * board_size);
	if (argc != 2 || ft_parse_clues(argv[1], clues, board_size) != 0) // wrong arg count or parsing failed 
	{
		ft_print("Wrong input\n");
		return (0); // Wrong Input
	}
	x = 0;
	y = 0;
	board = malloc(sizeof(unsigned short *) * board_size);
	while (x < board_size)
	{
		board[x] = malloc(sizeof(unsigned short) * board_size);
		y = 0;
		while (y < board_size)
		{
			board[x][y] = (1 << board_size) - 1;
			y++;
		}
		x++;
	}
	ft_solve_skyscraper(board, clues, board_size);
	ft_print_board(board, board_size);
	free(clues);
	free(board);
	return (0);
}