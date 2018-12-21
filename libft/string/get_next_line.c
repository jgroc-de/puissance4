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

char	*aux_join(char **line, t_list *node, int max)
{
	t_list	*tmp;
	int		len;
	char	*test;

	tmp = node;
	//ft_printf("\n ** copy **\n");
	//ft_printf("max init: %d\n", max);
	if (!tmp)
		return (NULL);
	if ((test = ft_strchr(tmp->content, '\n')))
	{
		len = test - (char*)tmp->content;
		//ft_printf("copy \\n: %s---\n", tmp->content);
		//ft_printf("max: %d\n", max);
		//ft_printf("len: %d\n", len);
		(*line)[max] = '\0';
		max -= len;
		ft_strncpy(*line + max, tmp->content, len);
		//ft_printf("line \\n: %s---\n", *line + max);
		tmp = tmp->next;
	}
	while (tmp)
	{
		max -= tmp->content_size;
		//ft_printf("copy: %s---\n", tmp->content);
		//ft_printf("max: %d\n", max);
		ft_strncpy(*line + max, tmp->content, tmp->content_size);
		//ft_printf("line: %s---\n*\n", *line + max);
		tmp = tmp->next;
	}
	ft_lstdel(&node, &ft_del);
	//ft_printf("\n ** fin copy **\n");
	return (*line);
}

int	aux_lstadd(t_list **node, char *save, int *status, int *len)
{
	t_list	*tmp;
	char	*test;

	//ft_printf("status: %d\n", *status);
	//ft_printf("save: %s\n", save);
	if (!(tmp = ft_lstnew(save, *status + 1)))
		return (0);
	((char*)tmp->content)[*status] = '\0';
	tmp->content_size--;
	//ft_printf("save: %s\n", tmp->content);
	ft_lstadd(node, tmp);
	ft_bzero(save, BUFF_SIZE + 1);
	if ((test = ft_strchr(tmp->content, '\n')))
	{
		*len += test - (char*)tmp->content;
		//ft_printf("\\n en sortie: %s\n", test + 1);
		ft_strcpy(save, test + 1);
		return (2);
	}
	else
	{
		//ft_printf("\\n nop\n");
		*len += *status;
		return (1);
	}
}

int		aux_read_loop(t_list **node, char *save, const int fd, int *status)
{
	int	len;
	int	out;

	out = 1;
	len = 0;
	//ft_printf(" ** read loop ** \n");
	if (*status > 0)
	{
		if (!(out = aux_lstadd(node, save, status, &len)))
			return (-1);
	}
	while (*status && out == 1)
	{
		if ((*status = read(fd, save, BUFF_SIZE)) == -1)
			return (-1);
		if (*status && !(out = aux_lstadd(node, save, status, &len)))
			return (-1);
	}
	save[*status] = '\0';
	//ft_printf(" ** fin read ** \n");
	return (len);
}

int				get_next_line(const int fd, char **line)
{
	static char		save[BUFF_SIZE + 1];
	t_list			*node;
	int				len;
	int				status;

	//ft_printf("---start---\n");
	node = NULL;
	if (!(status = ft_strlen(save)))
		status = -1;
	//ft_printf("\nsave: *%s*\n", save);
	//ft_printf("save length: %d\n", status);
	if (fd < 0 || !(line))
		return (ERROR);
	if ((len = aux_read_loop(&node, save, fd, &status)) == -1)
		return (ERROR);
	if (!(*line = ft_strnew(len)))
	{
		ft_lstdel(&node, &ft_del);
		return (-1);
	}
	//set line
	aux_join(line, node, len);
	if (len == 0 && status == 0)
		free(*line);
	//ft_printf("total length: %d\n", len);
	//ft_printf("\nsave: *%s*\n", save);
	//ft_printf("status: %d\n", status);
	//ft_printf("---end---\n");
	return (status >= 1? 1 : 0);
}
