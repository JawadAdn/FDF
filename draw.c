/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:08:32 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/03 03:42:33 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"
#include <stdio.h>

t_point		**transposee(t_point **tab, t_size *size, t_size *size_par)
{
	t_point	**map;
	int		i;
	int		j;
	int		var;

	map = malloc_mat(size->col, size->l);
	size_par->l = size->col;
	size_par->col = size->l;
	i = 0;
	while (i < size_par->l)
	{
		j = 0;
		while (j < size_par->col)
		{
			map[i][j] = tab[j][i];
			var = map[i][j].x;
			map[i][j].x = tab[j][i].y;
			map[i][j].y = var;
			j++;
		}
		i++;
	}
	return (map);
}

void		draw_map(t_point **map, t_size *size, t_window *fdf)
{
	int y;
	int x;

	y = 0;
	while (y < size->l)
	{
		x = 0;
		while (x < size->col)
		{
			if (x + 1 != size->col)
				draw_line(map[y][x], map[y][x + 1], fdf);
			if (y + 1 != size->l)
				draw_line(map[y][x], map[y + 1][x], fdf);
			x++;
		}
		y++;
	}
}

void		draw_line(t_point start, t_point end, t_window *fdf)
{
	t_br_var	br;
	int			i;
	float		x;
	float		y;

	br.dx = end.x - start.x;
	br.dy = end.y - start.y;
	br.step = abs(br.dx) > abs(br.dy) ? abs(br.dx) : abs(br.dy);
	br.xincr = br.dx / (double)br.step;
	br.yincr = br.dy / (double)br.step;
	i = 0;
	x = start.x + 250;
	y = start.y + 250;
	while (i <= br.step)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, start.color);
		x = x + br.xincr;
		y = y + br.yincr;
		i++;
	}
}
