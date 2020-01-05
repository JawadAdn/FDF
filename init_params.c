/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:52:14 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/05 01:58:25 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"
#include <unistd.h>

void	free_map(t_point **map, t_size *size)
{
	int i;
	
	i = 0;
	while (i < size->l)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	menu(t_window *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 10, 0xFFFFFF, "Menu");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 30, 0xFFFFFF,
			"P : Parallel");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 50, 0xFFFFFF, "I : ISO");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 70, 0xFFFFFF,
			"Fleche haute : Augmenter Z");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 90, 0xFFFFFF,
			"Fleche bas :   diminuer Z");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 110, 0xFFFFFF,
			"ESC :   Quitter");
}

void	options(int key, t_data *data, int a, int *z)
{
	if (key == 126 && a == 1)
	{
		(*z)++;
		draw_iso(data->map, data->size, data->fdf, *z);
	}
	else if (key == 125 && a == 1)
	{
		(*z)--;
		draw_iso(data->map, data->size, data->fdf, *z);
	}
	else
	{
		menu(data->fdf);
		draw_parallel(data->map, data->size, data->fdf);
	}
}

int		deal_key(int key, void *params)
{
	t_data		*data;
	static int	a;
	static int	z;

	data = (t_data *)params;
	mlx_clear_window(data->fdf->mlx_ptr, data->fdf->win_ptr);
	if (key == 53)
		exit(0);
	else if (key == 34)
	{
		a = 1;
		draw_iso(data->map, data->size, data->fdf, z);
	}
	else if (key == 35)
	{
		a = 0;
		draw_parallel(data->map, data->size, data->fdf);
	}
	else
		options(key, data, a, &z);
	return (0);
}

void	init_params(t_data *data)
{
	data->fdf->mlx_ptr = mlx_init();
	data->fdf->win_ptr = mlx_new_window(data->fdf->mlx_ptr, 1000, 1000, "fdf");
	menu(data->fdf);
	draw_parallel(data->map, data->size, data->fdf);
	mlx_key_hook(data->fdf->win_ptr, &deal_key, data);
	mlx_loop(data->fdf->mlx_ptr);
}
