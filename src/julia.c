/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:42:35 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 16:24:07 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	julia_draw(long double c_r, long double c_i,
		t_vector2 *v, t_data *data)
{
	long double	zr;
	long double zi;
	long double tmp;
	int			i;

	zr = v->x / data->f->zoom + data->pos->v1.x;
	zi = v->y / data->f->zoom + data->pos->v1.y;
	i = 0;
	while (i < data->f->iteration && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + c_r;
		zi = 2 * tmp * zi + c_i;
		++i;
		if (i == data->f->iteration)
			pixel_color(data, v, 0x0a2440);
		else
			pixel_color(data, v, 0x0a2440 * i);
	}
}

static void	julia_compute(long double img_x, long double img_y, t_data *data)
{
	t_vector2	vec;
	int			offset;
	int			start;

	offset = data->width / data->threads->nth;
	start = offset * get_thread(data, pthread_self());
	vec.x = start - 1;
	while (vec.x < img_x && vec.x < data->width && vec.x < start + offset)
	{
		vec.y = -1;
		while (vec.y < img_y && vec.y < data->height)
		{
			++(vec.y);
			julia_draw(data->f->c_re, data->f->c_im, &vec, data);
		}
		++(vec.x);
	}
}

void		*julia_start(void *vdata)
{
	long double img_x;
	long double img_y;
	t_data		*data;

	data = (t_data *)vdata;
	img_x = (data->pos->v2.x - data->pos->v1.x) * data->f->zoom;
	img_y = (data->pos->v2.y - data->pos->v1.y) * data->f->zoom;
	julia_compute(img_x, img_y, data);
	pthread_exit(NULL);
	return (NULL);
}
