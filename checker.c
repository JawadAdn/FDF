/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 23:23:56 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/01 00:24:51 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"
#include <stdio.h>

void		file_checker(int argc, char **argv, t_size *size)
{
	int fd;
	int resp;

	if (argc != 2)
	{
		perror("USAGE : ./fdf fileName");
		exit(-1);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		resp = reader(fd, size);
		if (resp == -1)
			perror("File doesn't Have same columns");
		else if (resp == -2)
			perror("File contains non-numeric input");
		else if (resp == -3)
			perror("File contains False Colors");
		if (resp == -1 || resp == -2 || resp == -3)
			exit(-1);
		else
			ft_putstr("File is valid");
	}
	close(fd);
}
