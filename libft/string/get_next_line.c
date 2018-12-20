/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:17:45 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/08 14:26:04 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../printf/libprintf.h"

static char	*aux_join(char **line, t_list *node)
{
	int		len;
	t_list	*tmp;
	char	*str;

	len = 0;
	tmp = node;
	while (tmp)
	{
		*(strchr(tmp->content, '\n')) = '\0';
		ft_printf("len node: %d\n", strlen(tmp->content));
		ft_printf("node: %s\n", tmp->content);
		ft_strcpy(line[len], (char*)tmp->content);
		if (!tmp->next)
			break ;
		len += tmp->content_size;
		tmp = tmp->next;
	}
	str = strchr((char*)tmp->content, '\n');
	if (!str)
		str = (char*)tmp->content;
	str = ft_strcpy((char*)tmp->content, str);
	return (str);
}

static int		aux_read_loop(t_list **save, char *str,
		char *save, const int fd)
{
	int		status;
	int		out;
	int		len;
	t_list	*node;

	status = 1;
	len = 0;
	out = 1;
	if (*str)
	{
		if (!(node = ft_lstnew(str, ft_strlen(str) + 1)))
			return (-1);
		ft_lstadd(save, node);
	}
	while (status && out)
	{
		status = read(fd, str, BUFF_SIZE);
		if (status == -1)
			return (-1);
		if ((*line = ft_strchr(str, '\n')))
		{
			**line = '\0';

			out = 1;
		}
		if (!(node = ft_lstnew(str, ft_strlen(str) + 1)))
			return (-1);
		ft_lstadd(save, node);
		len += status;
		ft_printf("\tlen: %d\n", len);
	}
	ft_printf("len: %d\n", len - 1);
	if (!(*line = ft_strnew(sizeof(char) * (len - 1))))
		return (-1);
	return (status - 1);
}

int				get_next_line(const int fd, char **line)
{
	static char		save[BUFF_SIZE + 1];
	char			str[BUFF_SIZE + 1];
	t_list			*node;
	int				status;

	(void)save;
	node = NULL;
	*line = save;
	ft_printf("\nsave: %s\n", save);
	if (fd < 0 || !(line))
		return (ERROR);
	if (*line)
	{
		ft_strcpy(str, *line);
		free(*line);
	}
	else
		(str[0] = '\0');
	if ((status = aux_read_loop(&node, str, save, fd)) == -1)
		return (ERROR);
	aux_join(line, node);
	ft_printf("status: %d\n", status);
	return (status > 1? 1 : 0);
}
