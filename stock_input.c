/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 23:45:01 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/05 01:39:47 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"
#include <math.h>
#include <stdio.h>

t_point		**malloc_mat(int l, int col)
{
	static t_point	**tab;
	int				i;

	i = 0;
	if (!(tab = (t_point **)malloc(l * sizeof(t_point *))))
		perror("can't allocate tab in malloc_mat\n");
	while (i < l)
	{
		if (!(tab[i] = (t_point *)malloc(col * sizeof(t_point))))
			perror("can' allocate l29 stock_input\n");
		i++;
	}
	return (tab);
}

int			ft_hex(char *str)
{
	int som;
	int i;

	i = 0;
	som = 0;
	str += 2;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			som += pow(16, i) * (str[i] - '0');
		else
		{
			str[i] = ft_toupper(str[i]);
			som += pow(16, i) * (str[i] - 55);
		}
		i++;
	}
	return (som);
}

void		extract_color_altitude(char **res, int j, t_point **tab, int i)
{
	int		k;
	char	*str;

	k = 0;
	str = (char *)malloc((ft_strlen(res[j]) + 1) * sizeof(char));
	while (res[j][k] != '\0' && res[j][k] != ',')
	{
		str[k] = res[j][k];
		k++;
	}
	str[k] = '\0';
	if (res[j][k] == '\0')
	{
		tab[i][j].z = ft_atoi(str);
		tab[i][j].color = 0xFFFFFF;
	}
	else
	{
		tab[i][j].z = ft_atoi(str);
		tab[i][j].color = ft_hex(ft_strsub(res[j], k + 1, ft_strlen(res[j])));
	}
	free(str);
	str = NULL;
}

void		copy_string_to_point_tab(char **res, t_point **tab,
		t_size *size, int i)
{
	int j;

	j = 0;
	while (j < size->col && res[j] != '\0')
	{
		tab[i][j].x = i;
		tab[i][j].y = j;
		extract_color_altitude(res, j, tab, i);
		j++;
	}
}

void	free_char(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		  free(res[i]);
		  i++;
	}
	free(res);
}

t_point		**stock_input(t_size *size, char **argv)
{
	t_point	**tab;
	int		fd;
	char	*line;
	char	**res;
	int		i;

	tab = malloc_mat(size->l, size->col);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		res = ft_strsplit(line, ' ');
		free(line);
		line = NULL;
		copy_string_to_point_tab(res, tab, size, i);
		i++;
		free_char(res);
	}
	return (tab);
}
