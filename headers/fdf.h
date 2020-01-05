/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:24:01 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/05 01:59:40 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;

}				t_window;

typedef struct	s_point
{
	int x;
	int y;
	int z;
	int color;
}				t_point;

typedef struct	s_size
{
	int l;
	int col;
}				t_size;

typedef struct	s_data
{
	t_point		**map;
	t_size		*size;
	t_window	*fdf;
}				t_data;

typedef struct	s_brensenham_var
{
	int			dx;
	int			dy;
	int			step;
	double		xincr;
	double		yincr;
}				t_br_var;

void			print_tab(t_point **map, t_size *size);
void			draw_iso(t_point **tab, t_size *size, t_window *fdf, int z);
t_point			**malloc_mat(int l, int col);
int				reader(int fd, t_size *size);
void			file_checker(int argc, char **argv, t_size *size);
t_point			**stock_input(t_size *size, char **argv);
void			init_params(t_data *data);
void			draw_line(t_point start, t_point end, t_window *fdf);
void			draw_map(t_point **map, t_size *size, t_window *fdf);
void			draw_new_tab(t_point **map, t_size *size, t_window *fdf);
void			add_some_space(t_point **map, t_size *size);
void			draw_parallel (t_point **tab, t_size *size, t_window *fdf);
t_point			**transposee(t_point **tab, t_size *size, t_size *size_par);
void			menu(t_window *fdf);
void			rotate(t_data *data, int teta);
void			free_map(t_point **map, t_size *size);
#endif
