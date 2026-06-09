/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_bitwise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:37:50 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 12:31:52 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_mask_or(unsigned short *dest, unsigned short *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] |= src[i];
		i++;
	}
}

void	ft_mask_and(unsigned short *dest, unsigned short *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] &= src[i];
		i++;
	}
}

int	ft_mask_equals(unsigned short *a, unsigned short *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}
