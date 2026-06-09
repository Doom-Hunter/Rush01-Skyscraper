/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_row.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:03:18 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 12:31:38 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_left_clues(unsigned short *row_mask,
			int *clues, int row, int size);
int		ft_check_right_clues(unsigned short *row_mask,
			int *clues, int row, int size);
void	ft_mask_or(unsigned short *dest, unsigned short *src, int size);
void	ft_print(char *str);
void	ft_print_binary(unsigned short mask, int size);
int		ft_is_line_unique(unsigned short *mask, int size);
int		ft_check_unique(unsigned short *mask, int size);

int	ft_check_row(unsigned short masks[3][9],
		int *clues, int row_depth[2], int size)
{
	int	row;
	int	is_valid;

	row = row_depth[0];
	is_valid = ft_is_line_unique(masks[1], size);
	is_valid &= ft_check_left_clues(masks[1], clues, row, size);
	is_valid &= ft_check_right_clues(masks[1], clues, row, size);
	if (is_valid)
		ft_mask_or(masks[2], masks[1], size);
	return (is_valid);
}

int	ft_permute_row(unsigned short masks[3][9],
		int *clues, int row_depth[2], int size)
{
	int	i;
	int	col;

	col = row_depth[1];
	if (col == size)
	{
		ft_check_row(masks, clues, row_depth, size);
		return (0);
	}
	else
	{
		i = 0;
		while (i < size)
		{
			if (masks[0][col] & 1 << i)
			{
				masks[1][col] = 1 << i;
				row_depth[1]++;
				ft_permute_row(masks, clues, row_depth, size);
			}
			row_depth[1] = col;
			i++;
		}
	}
	return (0);
}

void	ft_init_row_masks(unsigned short **board, unsigned short masks[3][9],
		int row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		masks[0][i] = board[i][row];
		masks[1][i] = 0;
		masks[2][i] = 0;
		i++;
	}
}

int	ft_calc_rows(unsigned short **board, int *clues, int size, int *changed)
{
	int				x;
	int				row;
	int				row_depth[2];
	unsigned short	masks[3][9];

	row = 0;
	while (row < size)
	{
		row_depth[0] = row;
		row_depth[1] = 0;
		ft_init_row_masks(board, masks, row, size);
		ft_permute_row(masks, clues, row_depth, size);
		ft_check_unique(masks[2], size);
		x = 0;
		while (x < size)
		{
			if (board[x][row] != masks[2][x])
				*changed = 1;
			board[x][row] &= masks[2][x];
			x++;
		}
		row++;
	}
	return (*changed);
}
