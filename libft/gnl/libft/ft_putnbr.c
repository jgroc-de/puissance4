/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:42:32 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/11/21 18:17:32 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n > 0)
	{
		if ((n / 10))
		{
			ft_putnbr(n / 10);
			ft_putchar((n % 10) + '0');
		}
		else
			ft_putchar(n + '0');
	}
	else if (n == -2147483648)
	{
		ft_putstr("-2");
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	if (n == 0)
		ft_putchar('0');
}
