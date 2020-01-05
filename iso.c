/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 00:04:47 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/05 02:04:36 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"
#include <stdio.h>

static void	iso_cookbook(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599) + 200;
	*y = -z + (previous_x + previous_y) * sin(0.523599) + 250;
}

void		draw_iso(t_point **tab, t_size *size, t_window *fdf, int z)
{
	t_point	**map;
	t_size	size_par;
	int		i;
	int		j;

	map = transposee(tab, size, &size_par);
	i = 0;
	while (i < size_par.l)
	{
		j = 0;
		while (j < size_par.col)
		{
			iso_cookbook(&map[i][j].x, &map[i][j].y, map[i][j].z * z);
			j++;
		}
		i++;
	}
	draw_map(map, &size_par, fdf);
	menu(fdf);
	free_map(map, &size_par);
}
