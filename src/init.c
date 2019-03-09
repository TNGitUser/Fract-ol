/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:34:00 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/09 13:48:05 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_frac			*init_julia(int type)
{
	t_frac		*julia;

	if (!(julia = malloc(sizeof(t_frac))))
		ft_die("julia init failed.");
	julia->zoom = 100;
	julia->c_re = -0.7;
	julia->c_im = 0.27015;
	julia->iteration = 50;
	julia->type = type;
	return (julia);
}

t_frac			*init_mandelbrot(int type)
{
	t_frac		*man;

	if (!(man = malloc(sizeof(t_frac))))
		ft_die("mandelbrot init failed.");
	man->zoom = 100;
	man->c_re = -0.5;
	man->c_im = 1;
	man->iteration = 50;
	man->type = type;
	return (man);
}

t_frac			*init_burn(int type)
{
	t_frac		*burn;

	if (!(burn = malloc(sizeof(t_frac))))
		ft_die("burn init failed.");
	burn->zoom = 100;
	burn->c_re = -0.7;
	burn->c_im = 0.27015;
	burn->iteration = 50;
	burn->type = type;
	return (burn);
}

t_frac			*init_tri(int type)
{
	t_frac		*tri;

	if (!(tri = malloc(sizeof(t_frac))))
		ft_die("tri init failed.");
	tri->zoom = 100;
	tri->c_re = -0.7;
	tri->c_im = 0.27015;
	tri->iteration = 50;
	tri->type = type;
	return (tri);
}

t_data			*init_main(int thread_number, int type)
{
	t_data *data;

	data = NULL;
	if (!(data = malloc(sizeof(t_data))))
		ft_die("Init failed.");
	if (!(data->mlx = mlx_init()))
		ft_die("Mlx init failed.");
	if (!(data->mlx_win = mlx_new_window(data->mlx, 600, 600, "Fractol")))
		ft_die("Mlx new window failed.");
	data->width = 600;
	data->height = 600;
	init_farray(data);
	data->f = NULL;
	data->f = data->init[type > 3 ? 1 : type](type);
	if (data->f == NULL)
		ft_die("Fractal init failed.");
	data->f->cs = 0;
	init_palette(data);
	data->f->plocked = 0;
	data->f->smooth = 0;
	data->ea = 0;
	data->z = 0;
	data->ind = 1;
	init_threads(data, thread_number);
	return (data);
}
