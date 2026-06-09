/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_skyscraper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:54:29 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 12:30:43 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_calc_rows(unsigned short **board, int *clues, int size, int *changed);
int		ft_calc_cols(unsigned short **board, int *clues, int size, int *changed);
int		ft_number_from_mask(unsigned short mask);
int		ft_check_atomic(unsigned short **board, int size, int *changed);

int	ft_is_used(unsigned short *perm, int index, unsigned short current)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (perm[i] == current)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_solved(unsigned short **board, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (ft_number_from_mask(board[x][y]) < 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_solve_skyscraper(unsigned short **board, int *clues, int size)
{
	int	solved;
	int	hard_limit;
	int	changed;

	hard_limit = 10000;
	solved = 0;
	while (!solved)
	{
		changed = 0;
		ft_calc_rows(board, clues, size, &changed);
		ft_calc_cols(board, clues, size, &changed);
		ft_check_atomic(board, size, &changed);
		solved = ft_is_solved(board, size);
		hard_limit--;
	}
	return (0);
}
