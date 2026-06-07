/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:41:48 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 16:41:48 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_binary(unsigned short value)
{
	int	i;
	int	bit;

	i = 15;
	while (i >= 0)
	{
		bit = (value >> i) & 1;
		if (bit)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}