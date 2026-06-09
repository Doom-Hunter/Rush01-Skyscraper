/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnay-min <tnay-min@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 01:15:54 by tnay-min          #+#    #+#             */
/*   Updated: 2026/06/09 00:40:47 by tnay-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int	carry;
	int	digit;

	carry = nb / 10;
	digit = nb - carry * 10;
	if (carry < 0 || digit < 0)
	{
		ft_putchar('-');
		carry *= -1;
		digit *= -1;
	}
	if (carry > 0)
	{
		ft_putnbr(carry);
	}
	ft_putchar(48 + digit);
}
