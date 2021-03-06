/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:40:15 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 14:43:30 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline size_t	ft_putendl_fd(const char *s, int fd)
{
	return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
}
