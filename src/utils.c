/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:52:21 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/27 16:58:12 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	init_palette(t_data *data)
{
	if (data->f->cs == 1)
		data->f->palette = color_palette(OUTER_COLOR1, INTER_COLOR1, 50);
	else if (data->f->cs == 2)
		data->f->palette = color_palette(OUTER_COLOR2, INTER_COLOR2, 50);
	else
		data->f->palette = color_palette(OUTER_COLOR0, INTER_COLOR0, 50);
}

void	init_image(t_data *data)
{
	t_image	*image;

	if (!(image = malloc(sizeof(t_image))))
		ft_die("Image init failed.");
	image->ptr = NULL;
	image->img = NULL;
	image->bpp = 0;
	image->line_size = 0;
	image->endian = 0;
	data->image = image;
	init_draw(data);
}

void	init_pos(t_data *data)
{
	t_pos	*pos;

	if (!(pos = malloc(sizeof(t_pos))))
		ft_die("Pos init failed.");
	pos->origin.x = -2.92;
	pos->origin.y = -2.92;
	pos->v1.x = -2.92;
	pos->v1.y = -2.92;
	pos->v2.x = 4;
	pos->v2.y = 4;
	pos->vmouse.x = 0;
	pos->vmouse.y = 0;
	data->pos = pos;
	init_image(data);
}

void	init_threads(t_data *data, int thread_number)
{
	t_thr	*threads;

	if (!(threads = malloc(sizeof(t_thr))))
		ft_die("Threads init failed.");
	threads->nth = thread_number;
	if (!(threads->workers = malloc(sizeof(pthread_t) * thread_number)))
		ft_die("Workers init failed.");
	data->threads = threads;
	init_pos(data);
}

void	init_farray(t_data *data)
{
	data->draw[0] = &julia_start;
	data->draw[1] = &man_start;
	data->draw[2] = &tri_start;
	data->draw[3] = &burn_start;
	data->init[0] = &init_julia;
	data->init[1] = &init_mandelbrot;
	data->init[2] = &init_tri;
	data->init[3] = &init_burn;
}
