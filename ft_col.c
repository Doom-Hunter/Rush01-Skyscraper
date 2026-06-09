/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:03:18 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 12:31:22 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_top_clues(unsigned short *col_mask,
			int *clues, int col, int size);
int		ft_check_bottom_clues(unsigned short *col_mask,
			int *clues, int col, int size);
void	ft_mask_or(unsigned short *dest, unsigned short *src, int size);
int		ft_is_line_unique(unsigned short *mask, int size);
int		ft_check_unique(unsigned short *mask, int size);

int	ft_check_col(unsigned short masks[3][9],
		int *clues, int col_depth[2], int size)
{
	int	col;
	int	is_valid;

	col = col_depth[0];
	is_valid = ft_is_line_unique(masks[1], size);
	is_valid &= ft_check_top_clues(masks[1], clues, col, size);
	is_valid &= ft_check_bottom_clues(masks[1], clues, col, size);
	if (is_valid)
		ft_mask_or(masks[2], masks[1], size);
	return (is_valid);
}

int	ft_permute_col(unsigned short masks[3][9],
		int *clues, int col_depth[2], int size)
{
	int	i;
	int	row;

	row = col_depth[1];
	if (row == size)
	{
		ft_check_col(masks, clues, col_depth, size);
		return (0);
	}
	else
	{
		i = 0;
		while (i < size)
		{
			if (masks[0][row] & 1 << i)
			{
				masks[1][row] = 1 << i;
				col_depth[1]++;
				ft_permute_col(masks, clues, col_depth, size);
			}
			col_depth[1] = row;
			i++;
		}
	}
	return (0);
}

void	ft_init_col_masks(unsigned short **board, unsigned short masks[3][9],
		int col, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		masks[0][i] = board[col][i];
		masks[1][i] = 0;
		masks[2][i] = 0;
		i++;
	}
}

int	ft_calc_cols(unsigned short **board, int *clues, int size, int *changed)
{
	int				y;
	int				col;
	int				col_depth[2];
	unsigned short	masks[3][9];

	col = 0;
	while (col < size)
	{
		col_depth[0] = col;
		col_depth[1] = 0;
		ft_init_col_masks(board, masks, col, size);
		ft_permute_col(masks, clues, col_depth, size);
		ft_check_unique(masks[2], size);
		y = 0;
		while (y < size)
		{
			if (board[col][y] != masks[2][y])
				*changed = 1;
			board[col][y] &= masks[2][y];
			y++;
		}
		col++;
	}
	return (*changed);
}
