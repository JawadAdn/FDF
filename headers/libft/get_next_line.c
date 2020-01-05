/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 22:22:37 by mel-adna          #+#    #+#             */
/*   Updated: 2019/12/26 22:34:45 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			free_node(int fd, t_node **lst, char **line, t_node *tmp)
{
	t_node			*p;
	t_node			*q;

	*line = NULL;
	ft_strdel(&(tmp->str));
	q = *lst;
	if ((*lst)->fd == fd)
		*lst = (*lst)->next;
	else
	{
		while (q)
		{
			if (q->fd == fd)
				break ;
			p = q;
			q = q->next;
		}
		if (q)
			p->next = q->next;
	}
	free(q);
	q = NULL;
	return (0);
}

static	t_node		*ft_search_node(int fd, t_node **lst)
{
	t_node			*p;
	t_node			*q;
	t_node			*prev;

	p = *lst;
	while (p)
	{
		if (p->fd == fd)
			return (p);
		prev = p;
		p = p->next;
	}
	if (!(q = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	q->fd = fd;
	q->str = NULL;
	q->next = NULL;
	if (*lst == NULL)
		*lst = q;
	else
		prev->next = q;
	return (q);
}

static int			ft_copyline(char **line, char *arr, char c)
{
	int				len;

	len = 0;
	while (arr[len] && arr[len] != c)
		len++;
	*line = ft_strsub(arr, 0, len);
	if (!*line)
		return (-1);
	return (len);
}

static int			ft_check_tmp(int ret, t_node *tmp, char **line)
{
	char			*fr;

	ret = ft_copyline(line, tmp->str, '\n');
	if ((tmp->str)[ret] != '\0')
	{
		fr = tmp->str;
		tmp->str = ft_strdup(&(fr[ret + 1]));
		if (tmp->str == NULL)
			return (-1);
		ft_strdel(&fr);
	}
	else if ((tmp->str)[ret] == '\0')
		ft_strdel(&(tmp->str));
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static	t_node	*lst;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_node			*tmp;
	char			*fr;

	if (!line || fd < 0 || (read(fd, buff, 0) < 0))
		return (-1);
	tmp = ft_search_node(fd, &lst);
	if (tmp->str == NULL)
		tmp->str = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		fr = tmp->str;
		buff[ret] = '\0';
		tmp->str = ft_strjoin(fr, buff);
		ft_strdel(&fr);
		if (ft_strchr(tmp->str, '\n') != NULL)
			break ;
	}
	if (ret == 0 && *(tmp->str) == '\0')
		return (free_node(fd, &lst, line, tmp));
	return (ft_check_tmp(ret, tmp, line));
}
