/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_skyscraper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:53:48 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 19:53:48 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_used(unsigned short *perm, int index, unsigned short current);

static int	ft_get_bit_index(unsigned short mask)
{
	int	i;

	i = 1;
	while (mask > 1)
	{
		mask >>= 1;
		i++;
	}
	return (i);
}

int	ft_check_col_clues(unsigned short *col, int *clues, int size, int col_id)
{
	int	i;
	int	max;
	int	visible;
	int	curr;

	max = 0;
	visible = 0;
	i = -1;
	while (++i < size)
	{
		curr = ft_get_bit_index(col[i]);
		if (curr > max && ++visible)
			max = curr;
	}
	if (clues[col_id] != visible)
		return (1);
	max = 0;
	visible = 0;
	i = size;
	while (--i >= 0)
	{
		curr = ft_get_bit_index(col[i]);
		if (curr > max && ++visible)
			max = curr;
	}
	return (clues[size + col_id] != visible);
}

void	ft_filter_col(unsigned short **data, unsigned short *perm,
					int index, int size)
{
	int	i;
	int	*meta;

	if (index == size)
	{
		meta = (int *)data[3];
		if (ft_check_col_clues(perm, (int *)data[2], size, meta[0]) == 0)
		{
			i = -1;
			while (++i < size)
				data[1][i] |= perm[i];
		}
		return ;
	}
	i = 0;
	while (i < size)
	{
		if ((data[0][index] & (1 << i)) && !ft_is_used(perm, index, 1 << i))
		{
			perm[index] = 1 << i;
			ft_filter_col(data, perm, index + 1, size);
		}
		i++;
	}
}

void	ft_permute_col(unsigned short **board, int *clues, int size, int col_id)
{
	int				i;
	int				meta[1];
	unsigned short	*data[4];
	unsigned short	*perm;

	data[0] = malloc(sizeof(unsigned short) * size);
	data[1] = malloc(sizeof(unsigned short) * size);
	perm = malloc(sizeof(unsigned short) * size);
	if (!data[0] || !data[1] || !perm)
		return ;
	i = -1;
	while (++i < size)
	{
		data[0][i] = board[i][col_id];
		data[1][i] = 0;
	}
	meta[0] = col_id;
	data[2] = (unsigned short *)clues;
	data[3] = (unsigned short *)meta;
	ft_filter_col(data, perm, 0, size);
	i = -1;
	while (++i < size)
		board[i][col_id] &= data[1][i];
	free(data[0]);
	free(data[1]);
	free(perm);
}