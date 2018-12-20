/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:53:17 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/05 14:10:47 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		neg;

	res = 0;
	neg = 0;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)) && *str != '\200')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*(str++) - '0');
	if (neg == 1)
		res = -res;
	return (res);
}