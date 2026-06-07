/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_visible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:45:35 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 22:48:12 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_bit_index(unsigned short mask)
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

int	ft_count_visible(unsigned short *row_col, int size, int start, int step)
{
	int	max;
	int	visible;
	int	curr;
	int	count;

	max = 0;
	visible = 0;
	count = 0;
	while (count < size)
	{
		curr = ft_get_bit_index(row_col[start]);
		if (curr > max)
		{
			max = curr;
			visible++;
		}
		start += step;
		count++;
	}
	return (visible);
}
