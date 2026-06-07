/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_clues.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:31:11 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/07 22:29:28 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_parse_clues(char *str, int *clues, int size)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (str_len != size * 8 - 1)
		return (1);
	while (i < str_len)
	{
		if (i % 2 == 0)
		{
			if (str[i] == 0 || str[i] < '1' || str[i] > 48 + size)
				return (1);
			clues[i / 2] = str[i] - 48;
		}
		else if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
