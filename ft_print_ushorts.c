/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_shorts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:31:26 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 15:31:26 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_ushorts(unsigned short *shorts, unsigned int size)
{
	unsigned int	i;
	
	i = 0;
	while (i < size)
	{
		write(1, shorts + i, sizeof(unsigned short));
		i++;
	}
}