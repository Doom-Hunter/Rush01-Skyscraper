/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_skyscraper_fancy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 00:29:28 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 14:14:37 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);
void	ft_print(char *str);
int		ft_calc_rows(unsigned short **board,
			int *clues, int size, int *changed);
int		ft_calc_cols(unsigned short **board,
			int *clues, int size, int *changed);
int		ft_number_from_mask(unsigned short mask);
int		ft_check_atomic(unsigned short **board, int size, int *changed);
void	ft_print_board_binary(unsigned short **board, int board_size);
int		ft_check_error(unsigned short **board, int board_size);

int	ft_count_solved(unsigned short **board, int size)
{
	int	x;
	int	y;
	int	solved;

	solved = 0;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (ft_number_from_mask(board[x][y]) > 0)
				solved++;
			y++;
		}
		x++;
	}
	return (solved);
}

int	ft_lock_in_cell(unsigned short **board, int size)
{
	int				x;
	int				y;
	unsigned short	i;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (ft_number_from_mask(board[x][y]) < 0)
			{
				i = 0;
				while (i < size)
				{
					if ((board[x][y] >> i & 1) == 1)
					{
						board[x][y] = 1 << i;
						return (1);
					}
					i++;
				}
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_debug(int progress, int loops, int loops_since_last_progress)
{
	ft_print("\rProgress: ");
	ft_putnbr(progress);
	ft_print("% | Iterations: ");
	ft_putnbr(loops);
	ft_print(" | ");
	ft_putnbr(loops_since_last_progress);
}

void	ft_solve(unsigned short **board, int *clues, int size, int *changed)
{
	ft_calc_rows(board, clues, size, changed);
	ft_calc_cols(board, clues, size, changed);
	ft_check_atomic(board, size, changed);
}

int	ft_solve_skyscraper_fancy(unsigned short **board, int *clues, int size)
{
	int		solved;
	int		changed;
	int		invalid;
	int		loops;
	int		loops_since_last_progress;

	invalid = 0;
	solved = 0;
	loops = 0;
	changed = 1;
	while (!invalid && solved != size * size)
	{
		ft_debug(100 * solved / (size * size),
			loops, loops_since_last_progress);
		if (ft_check_error(board, size)
			|| (!changed && ft_lock_in_cell(board, size) == 0))
			break ;
		changed = 0;
		ft_solve(board, clues, size, &changed);
		solved = ft_count_solved(board, size);
		ft_debug(100 * solved / (size * size),
			loops, loops_since_last_progress);
		loops++;
		loops_since_last_progress++;
	}
	ft_print("\n");
	return (invalid);
}
