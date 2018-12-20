/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:35:09 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/11/21 16:47:34 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_neg_case(int *n, char *s)
{
	s[0] = '-';
	if (*n == -2147483648)
	{
		s[1] = '2';
		*n = 147483648;
	}
	*n = ft_abs(*n);
}

char			*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	int		j;

	i = 0;
	j = n;
	while ((j = j / 10))
		i++;
	if (n < 0)
		i++;
	if ((s = ft_strnew(i + 1)))
	{
		if (n < 0)
			ft_neg_case(&n, s);
		if (n == 0)
			*s = '0';
		while (n)
		{
			s[i--] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (s);
}
