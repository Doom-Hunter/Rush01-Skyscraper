/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:31:41 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 23:28:40 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_print(char *str);
void	ft_print_board(unsigned short **board, int board_size);
int		ft_parse_clues(char *str, int *clues, int size);
int		ft_solve_skyscraper(unsigned short **board, int *clues, int size);
void	ft_malloc_board(unsigned short **board, int board_size);

int	main_bonus(int argc, char **argv)
{
	int				board_size;
	int				*clues;
	unsigned short	**board;

	board_size = 4;
	if (argc == 3 && ft_strlen(argv[2]) == 1
		&& *argv[2] >= '4' && *argv[2] <= '9')
		board_size = *argv[2] - '0';
	else if (argc != 2)
		return (0);
	clues = malloc(sizeof(int) * 4 * board_size);
	if (!clues || ft_parse_clues(argv[1], clues, board_size) != 0)
	{
		free(clues);
		return (0);
	}
	board = malloc(sizeof(unsigned short *) * board_size);
	ft_malloc_board(board, board_size);
	ft_solve_skyscraper(board, clues, board_size);
	ft_print_board(board, board_size);
	free(clues);
	free(board);
	return (0);
}
