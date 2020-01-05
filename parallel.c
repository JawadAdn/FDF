/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 00:05:33 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/05 02:08:25 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

void	draw_parallel(t_point **tab, t_size *size, t_window *fdf)
{
	t_point		**map;
	t_size		size_par;

	map = transposee(tab, size, &size_par);
	draw_map(map, &size_par, fdf);
	menu(fdf);
	free_map(map, &size_par);
}

void	add_some_space_horizontally(t_point **map, t_size *size)
{
	int i;
	int j;
	int k;
	int var;

	var = (size->col > size->l) ? size->col : size->l;
	j = 0;
	while (j < size->col)
	{
		i = 0;
		k = 0;
		while (i < size->l)
		{
			map[i][j].x += k;
			k += 0.5 * 1000 / var;
			i++;
		}
		j++;
	}
}

void	add_some_space_vertically(t_point **map, t_size *size)
{
	int i;
	int j;
	int k;
	int var;

	var = (size->col > size->l) ? size->col : size->l;
	i = 0;
	k = 0;
	while (i < size->l)
	{
		j = 0;
		k = 0;
		while (j < size->col)
		{
			map[i][j].y += k;
			k += 0.5 * 1000 / var;
			j++;
		}
		i++;
	}
}

void	add_some_space(t_point **map, t_size *size)
{
	add_some_space_horizontally(map, size);
	add_some_space_vertically(map, size);
}
