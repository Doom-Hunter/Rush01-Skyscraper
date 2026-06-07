/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_skyscraper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:54:29 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 23:28:06 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_permute_row(
			unsigned short **board, int *clues, int size, int row_id);
void	ft_permute_col(
			unsigned short **board, int *clues, int size, int col_id);
int		ft_number_from_mask(unsigned short mask);

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
	int	i;
	int	solved;
	int	hard_limit;

	hard_limit = 100;
	solved = 0;
	while (!solved && hard_limit > 0)
	{
		i = 0;
		while (i < size)
		{
			ft_permute_row(board, clues, size, i);
			ft_permute_col(board, clues, size, i);
			i++;
		}
		solved = ft_is_solved(board, size);
		hard_limit--;
	}
	return (0);
}
