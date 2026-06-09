/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:10:59 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 14:20:32 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_binary(unsigned short mask, int size)
{
	int		i;
	char	bit;

	i = size - 1;
	if (mask == 0)
		write(1, "\033[1;31m", 7);
	while (i >= 0)
	{
		if (mask & (1 << i))
			bit = '1';
		else
			bit = '0';
		write(1, &bit, 1);
		i--;
	}
	if (mask == 0)
		write(1, "\033[0;0m", 6);
}
