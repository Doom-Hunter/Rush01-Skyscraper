/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:53:48 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 22:48:02 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_used(unsigned short *perm, int index, unsigned short current);
void	ft_free_three(void *m1, void *m2, void *m3);
int		ft_count_visible(
			unsigned short *row_col, int size, int start, int step);

int	ft_check_col_clues(unsigned short *col, int *clues, int size, int col_id)
{
	int	visible;

	visible = ft_count_visible(col, size, 0, 1);
	if (clues[col_id] != visible)
		return (1);
	visible = ft_count_visible(col, size, size - 1, -1);
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
	ft_free_three(data[0], data[1], perm);
}
