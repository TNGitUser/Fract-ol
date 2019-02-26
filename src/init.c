/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:34:00 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/26 11:45:46 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static t_frac	*init_julia(void)
{
	t_frac		*julia;

	if (!(julia = malloc(sizeof(t_frac))))
		ft_die("julia init failed.");
	julia->move.x = 0;
	julia->move.y = 0;
	julia->zoom = 100;
	julia->c_re = -0.7;
	julia->c_im = 0.27015;
	julia->iteration = 50;
	julia->type = 0;
	return (julia);
}

static t_frac	*init_mandelbrot(void)
{
	t_frac		*man;

	if (!(man = malloc(sizeof(t_frac))))
		ft_die("mandelbrot init failed.");
	man->move.x = 0;
	man->move.y = 0;
	man->zoom = 100;
	man->c_re = -0.5;
	man->c_im = 1;
	man->iteration = 50;
	man->type = 1;
	return (man);
}

t_data			*init_main(int thread_number, int type)
{
	t_data *data;

	data = NULL;
	if (!(data = malloc(sizeof(t_data))))
		ft_die("Init failed.");
	if (!(data->mlx = mlx_init()))
		ft_die("Mlx init failed.");
	if (!(data->mlx_win = mlx_new_window(data->mlx, 600, 600, "0")))
		ft_die("Mlx new window failed.");
	data->width = 600;
	data->height = 600;
	data->f = NULL;
	if (type == 0)
		data->f = init_julia();
	if (type == 1)
		data->f = init_mandelbrot();
	if (data->f == NULL)
		ft_die("Fractal init failed.");
	data->f->plocked = 0;
	data->f->smooth = 0;
	init_threads(data, thread_number);
	return (data);
}
