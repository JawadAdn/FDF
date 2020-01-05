/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:38:34 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/04 23:21:46 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!(data->size = (t_size *)malloc(sizeof(t_size))))
		perror("can't allocate for window fdf in main");
	file_checker(argc, argv, data->size);
	data->map = stock_input(data->size, argv);
	data->fdf = (t_window *)malloc(sizeof(t_window));
	if (data->size->col < 250 && data->size->l < 250)
		add_some_space(data->map, data->size);
	init_params(data);
	return (0);
}
