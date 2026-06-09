/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:31:41 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/08 22:46:49 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_putchar(char c);
int		ft_print(char *str);
void	ft_print_board(unsigned short **board, int board_size);
void	ft_print_board_binary(unsigned short **board, int board_size);
int		ft_parse_clues(char *str, int *clues, int size);
int		ft_solve_skyscraper(unsigned short **board, int *clues, int size);
void	ft_malloc_board(unsigned short **board, int board_size);

int	main_debug(int argc, char **argv)
{
	int				board_size;
	int				*clues;
	unsigned short	**board;

	board_size = 4;
	clues = malloc(sizeof(int *) * 4 * board_size);
	if (argc != 2 || ft_parse_clues(argv[1], clues, board_size) != 0)
		return (0);
	board = malloc(sizeof(unsigned short *) * board_size);
	ft_malloc_board(board, board_size);
	ft_solve_skyscraper(board, clues, board_size);
	ft_print_board(board, board_size);
	ft_print_board_binary(board, board_size);
	free(clues);
	free(board);
	return (0);
}
