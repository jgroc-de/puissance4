/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:17:45 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/02 13:13:47 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		aux_ret(char **line, t_gnl *g)
{
	if (g->status == -1)
		return (0);
	if ((g->tmp = ft_strchr(*line, '\n')))
	{
		g->status = g->tmp - *line;
		if (!(g->ltmp->content = ft_strdup(g->tmp + 1)))
			return (0);
		(*line)[g->status] = '\0';
	}
	return (1);
}

static char		*aux_join_free(char **line, t_gnl *g)
{
    g->str[g->status] = '\0';
	if (*line)
	{
		g->tmp = *line;
		*line = ft_strjoin(*line, g->str);
		ft_memdel((void*)&(g->tmp));
	}
	else
		*line = ft_strdup(g->str);
	return (*line);
}

static int      aux_read(char **line, t_gnl *g, const int fd)
{
	while (g->status > 0)
	{
		g->status = read(fd, g->str, BUFF_SIZE);
        if (g->status == -1 || !aux_join_free(line, g))
        {
            g->status = -1;
            return (ERROR);
        }
		if (ft_strchr(g->str, '\n'))
			g->status = -2;
	}
	return (g->status);
}

static t_list	*aux_init_g(t_list **node, t_gnl *g, int fd)
{
	g->status = 1;
	if (!(g->str = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (*node)
	{
		g->ltmp = *node;
		while (g->ltmp && g->ltmp->content_size != (size_t)fd)
			g->ltmp = g->ltmp->next;
		if (!(g->ltmp))
		{
			if (!(g->ltmp = ft_lstnew(NULL, fd)))
				return (NULL);
			ft_lstadd(node, g->ltmp);
		}
	}
	else
	{
		if (!(*node = ft_lstnew(NULL, fd)))
			return (NULL);
		g->ltmp = *node;
	}
	return (g->ltmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*node;
	t_gnl			g;

	if (fd < 0 || !(line) || !(aux_init_g(&node, &g, fd)))
		return (ERROR);
	*line = NULL;
	if (g.ltmp->content)
		if ((*line = ft_strdup(g.ltmp->content)) && (g.tmp = ft_strchr(*line, '\n')))
		    g.status = -2;
	if (g.status > 0)
		aux_read(line, &g, fd);
	ft_memdel((void*)&(g.ltmp->content));
	ft_memdel((void*)&(g.str));
	if (g.status != 0 || (*line && ft_strcmp(*line, "") != 0))
		return (aux_ret(line, &g) ? 1 : -1);
	ft_memdel((void*)line);
	node = ft_lstdel_relink(&(g.ltmp), &node, &ft_del);
	return (0);
}
