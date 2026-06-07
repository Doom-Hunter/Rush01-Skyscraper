/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_from_mask.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:56:39 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 19:56:39 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_number_from_mask(unsigned short mask)
{
	int	i;
	int	number;

	number = 0;
	i = 1;
	while (mask > 0)
	{
		if (mask & 1)
		{
			if (number)
				return (-2);
			number = i;
		}
		i++;
		mask >>= 1;
	}
	return (number);
}