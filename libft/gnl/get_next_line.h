/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:17:59 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/02 11:40:22 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 8
# define ERROR -1

typedef struct	s_gnl
{
	char	*str;
	char	*tmp;
	int		status;
	t_list	*ltmp;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
