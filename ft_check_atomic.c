/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atomic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:10:43 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 12:26:52 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_number_from_mask(unsigned short mask);

int	ft_atomic_mask(unsigned short *mask,
		unsigned short *atomic_mask, int *changed)
{
	int	number;

	number = ft_number_from_mask(*mask);
	if (number < 0 && *mask & *atomic_mask)
	{
		*mask &= ~*atomic_mask;
		*changed = 1;
	}
	else if (number > 0)
		*atomic_mask |= *mask;
	return (0);
}

int	ft_check_atomic_row(unsigned short **board, int size, int	*changed)
{
	int				x;
	int				y;
	unsigned short	atomics;

	y = 0;
	while (y < size)
	{
		x = 0;
		atomics = 0;
		while (x < size)
		{
			ft_atomic_mask(&board[x][y], &atomics, changed);
			x++;
		}
		x = size - 1;
		atomics = 0;
		while (x >= 0)
		{
			ft_atomic_mask(&board[x][y], &atomics, changed);
			x--;
		}
		y++;
	}
	return (1);
}

int	ft_check_atomic_col(unsigned short **board, int size, int	*changed)
{
	int				x;
	int				y;
	unsigned short	atomics;

	x = 0;
	while (x < size)
	{
		y = 0;
		atomics = 0;
		while (y < size)
		{
			ft_atomic_mask(&board[y][x], &atomics, changed);
			y++;
		}
		y = size - 1;
		atomics = 0;
		while (y >= 0)
		{
			ft_atomic_mask(&board[y][x], &atomics, changed);
			y--;
		}
		x++;
	}
	return (1);
}

int	ft_check_atomic(unsigned short **board, int size, int *changed)
{
	return (ft_check_atomic_row(board, size, changed)
		&& ft_check_atomic_col(board, size, changed));
}
