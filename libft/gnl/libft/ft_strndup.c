/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:06:42 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/08 18:33:02 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	while (s1[i] && i < n)
		i++;
	d = (char*)malloc(sizeof(*d) * (i + 1));
	if (d)
	{
		d = ft_strncpy(d, s1, i);
		d[i] = '\0';
	}
	return (d);
}
