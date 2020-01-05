/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:26:38 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/04 19:27:40 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

int		count_elem(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		check_color(char *t, int i)
{
	int k;

	if (t[i] != '0' && (t[i + 1] != 'x' || t[i + 1] != 'X'))
		return (-3);
	i = i + 2;
	k = 0;
	while (t[i] != '\0')
	{
		if (t[i] < '0' || (t[i] > '9' && t[i] < 'A') ||
				(t[i] > 'F' && t[i] < 'a') || t[i] > 'f')
			return (-3);
		i++;
		k++;
	}
	if (k < 2)
		return (-3);
	return (0);
}

int		check_number(char **t)
{
	int i;
	int j;

	i = 0;
	while (t[i])
	{
		j = 0;
		if (t[i][j] == '-' && t[i][j + 1] != '\0')
			j++;
		while (t[i][j] != '\0' && t[i][j] != ',')
		{
			if (ft_isdigit(t[i][j]) == 0)
				return (-2);
			j++;
		}
		if (t[i][j] == ',')
			return (check_color(t[i], j + 1));
		i++;
	}
	return (0);
}

int		check(int fd, t_size *size)
{
	char	*line;
	char	**res;
	int		cmp;
	int		c;

	size->l = 0;
	get_next_line(fd, &line);
	(size->l)++;
	res = ft_strsplit(line, ' ');
	size->col = count_elem(res);
	free(line);
	if ((c = check_number(res)) == -2)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		(size->l)++;
		res = ft_strsplit(line, ' ');
		free(line);
		cmp = count_elem(res);
		if (size->col != cmp)
			return (0);
		if (check_number(res) == -2 || check_number(res) == -3)
			return (check_number(res) + 1);
	}
	return (cmp);
}

int		reader(int fd, t_size *size)
{
	int resp;

	resp = check(fd, size);
	if (resp == 0)
		return (-1);
	if (resp == -1)
		return (-2);
	if (resp == -2)
		return (-3);
	return (resp);
}
