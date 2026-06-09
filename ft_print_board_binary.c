/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_board_binary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:01:54 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/08 21:15:50 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
int		ft_print(char *str);
int		ft_number_from_mask(unsigned short mask);
void	ft_print_binary(unsigned short mask, int size);

void	ft_print_board_binary(unsigned short **board, int board_size)
{
	int	x;
	int	y;

	x = 0;
	while (x < board_size)
	{
		y = 0;
		while (y < board_size)
		{
			ft_print_binary(board[y][x], board_size);
			if (y != board_size - 1)
				ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
