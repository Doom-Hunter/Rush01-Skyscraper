/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_unique.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:15:07 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 09:11:05 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_apply_unique(unsigned short *mask, unsigned short unique, int size)
{
	int				i;
	unsigned short	intersect;

	i = 0;
	while (i < size)
	{
		intersect = mask[i] & unique;
		if (intersect > 0)
		{
			if ((intersect & (intersect - 1)) == 0)
				mask[i] = intersect;
			else
				mask[i] &= unique;
		}
		i++;
	}
	return (1);
}

int	ft_check_unique(unsigned short *mask, int size)
{
	unsigned short	seen;
	unsigned short	dupe;
	unsigned short	unique;
	int				i;

	seen = 0;
	dupe = 0;
	unique = 0;
	i = 0;
	while (i < size)
	{
		dupe |= mask[i] & seen;
		seen |= mask[i];
		i++;
	}
	unique = seen & ~dupe;
	if (unique > 0)
		return (ft_apply_unique(mask, unique, size));
	return (0);
}
