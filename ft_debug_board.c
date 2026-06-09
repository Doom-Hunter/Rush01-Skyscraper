/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 22:45:27 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/08 22:46:33 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_print(char *str);
void	ft_print_board(unsigned short **board, int board_size);
void	ft_print_board_binary(unsigned short **board, int board_size);

void	ft_print_debug_board(unsigned short **board, int size, char *message)
{
	ft_print("============\n");
	ft_print(message);
	ft_print("\n============\n");
	ft_print_board(board, size);
	ft_print_board_binary(board, size);
}
