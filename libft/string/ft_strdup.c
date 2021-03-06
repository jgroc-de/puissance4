/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:28:51 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/11 17:10:08 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char*)malloc(sizeof(*s2) * (ft_strlen(s1) + 1));
	if (s2)
	{
		*s2 = '\0';
		ft_strcpy(s2, s1);
	}
	return (s2);
}
