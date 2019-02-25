/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:34:00 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 10:47:28 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static t_frac		*init_julia(void)
{
	t_frac		*julia;

	if (!(julia = malloc(sizeof(t_frac))))
		ft_die("julia init failed.");
	julia->area[0].x = 0;
	julia->area[0].y = 0;
	julia->area[1].x = 1000;
	julia->area[1].y = 1000;
	julia->move.x = 0;
	julia->move.y = 0;
	julia->zoom = 1;
	julia->cRe = -0.7;
	julia->cIm = 0.27015;
	return (julia);
}

static t_frac		*init_mandelbrot(void)
{
	t_frac		*man;

	if (!(man = malloc(sizeof(t_frac))))
		ft_die("mandelbrot init failed.");
	man->area[0].x = 0;
	man->area[0].y = 0;
	man->area[1].x = 1000;
	man->area[1].y = 1000;
	man->move.x = 0;
	man->move.y = 0;
	man->zoom = 1;
	man->cRe = 0;
	man->cIm = 0;
	return (man);
}

static t_thr	*init_threads(int thread_number)
{
	t_thr	*threads;

	if (!(threads = malloc(sizeof(t_thr))))
		ft_die("Threads init failed.");
	threads->nth = thread_number;
	if (!(threads->workers = malloc(sizeof(pthread_t) * thread_number)))
		ft_die("Workers init failed.");
	return (threads);
}

t_data			*init_main(int thread_number, int type)
{
	t_data *data;

	data = NULL;
	if (!(data = malloc(sizeof(t_data))))
		ft_die("Init failed.");
	if (!(data->mlx = mlx_init()))
		ft_die("mlx init failed.");
	if (!(data->mlx_win = mlx_new_window(data->mlx, 1000, 1000, "0")))
		ft_die("mlx init failed.");
	data->width = 1000;
	data->height = 1000;
	data->threads = init_threads(thread_number);
	if (type == 0)
		data->f = init_julia();
	if (type == 1)
		data->f = init_mandelbrot();
	return (data);
}
