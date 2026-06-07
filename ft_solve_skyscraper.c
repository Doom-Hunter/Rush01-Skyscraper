/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:54:29 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 19:54:29 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_permute_row(unsigned short **board, int *clues, int size, int row_id);
void	ft_permute_col(unsigned short **board, int *clues, int size, int col_id);

int	ft_number_from_mask(unsigned short mask);

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

int	ft_solve_skyscraper(unsigned short **board, int *clues, int size)
{
	int	i;
	int	loop;

	loop = 0;
	while (loop < size)
	{
		i = 0;
		while (i < size)
		{
			ft_permute_row(board, clues, size, i);
			ft_permute_col(board, clues, size, i);
			i++;
		}
		loop++;
	}
	return (0);
}