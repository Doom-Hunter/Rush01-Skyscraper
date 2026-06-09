/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_clues.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:31:43 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/08 21:53:31 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_number_from_mask(unsigned short mask);

int	ft_is_line_unique(unsigned short *mask, int size)
{
	int				i;
	unsigned short	seen;

	i = 0;
	seen = 0;
	while (i < size)
	{
		if (seen & mask[i])
			return (0);
		seen |= mask[i];
		i++;
	}
	return (1);
}

int	ft_check_left_clues(unsigned short *row_mask, int *clues, int row, int size)
{
	int	left_clue;
	int	max;
	int	visible;
	int	i;
	int	number;

	max = 0;
	visible = 0;
	left_clue = clues[size * 2 + row];
	i = 0;
	while (i < size)
	{
		number = ft_number_from_mask(row_mask[i]);
		if (number > max)
		{
			max = number;
			visible++;
		}
		i++;
	}
	if (visible != left_clue)
		return (0);
	return (1);
}

int	ft_check_right_clues(
	unsigned short *row_mask, int *clues, int row, int size)
{
	int	right_clue;
	int	max;
	int	visible;
	int	i;
	int	number;

	max = 0;
	visible = 0;
	right_clue = clues[size * 3 + row];
	i = size - 1;
	while (i >= 0)
	{
		number = ft_number_from_mask(row_mask[i]);
		if (number > max)
		{
			max = number;
			visible++;
		}
		i--;
	}
	if (visible != right_clue)
		return (0);
	return (1);
}

int	ft_check_top_clues(unsigned short *col_mask, int *clues, int col, int size)
{
	int	top_clue;
	int	max;
	int	visible;
	int	i;
	int	number;

	max = 0;
	visible = 0;
	top_clue = clues[col];
	i = 0;
	while (i < size)
	{
		number = ft_number_from_mask(col_mask[i]);
		if (number > max)
		{
			max = number;
			visible++;
		}
		i++;
	}
	if (visible != top_clue)
		return (0);
	return (1);
}

int	ft_check_bottom_clues(
	unsigned short *col_mask, int *clues, int col, int size)
{
	int	bottom_clue;
	int	max;
	int	visible;
	int	i;
	int	number;

	max = 0;
	visible = 0;
	bottom_clue = clues[size + col];
	i = size - 1;
	while (i >= 0)
	{
		number = ft_number_from_mask(col_mask[i]);
		if (number > max)
		{
			max = number;
			visible++;
		}
		i--;
	}
	if (visible != bottom_clue)
		return (0);
	return (1);
}
