/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubicm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:09:50 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/09 13:48:31 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	color(int i, t_data *data, t_vector2 *v, int color)
{
	if (!data->f->smooth)
	{
		if (i == data->f->iteration)
			return ;
		else
			color = get_scolor(data) * i;
	}
	pixel_color(data, v, color);
}

static void	cubicm_draw(long double c_r, long double c_i,
		t_vector2 *v, t_data *data)
{
	long double	zr;
	long double zi;
	long double tmp;
	int			i;
	t_dvector2	vz;

	c_r = v->x / data->f->zoom + data->pos->v1.x;
	c_i = v->y / data->f->zoom + data->pos->v1.y;
	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < data->f->iteration && zr * zr + zi * zi < 4)
	{
		tmp = (zr * zr * zr) - 3 * zr * (zi * zi);
		zi = 3 * (zr * zr) * zi - (zi * zi * zi) + c_i;
		zr = tmp + c_r;
		++i;
	}
	vz.x = zr;
	vz.y = zi;
	color(i, data, v, normalize_color(i, &vz, data));
}

static void	cubicm_compute(long double xf_limit, long double yf_limit,
		t_data *data)
{
	t_vector2	vec;
	int			offset;
	int			start;

	offset = data->width / data->threads->nth;
	start = offset * get_thread(data, pthread_self());
	vec.x = start - 1;
	vec.x = vec.x > 0 ? vec.x : 0;
	while (vec.x < xf_limit && vec.x < data->width && vec.x < start + offset)
	{
		vec.y = 0;
		while (vec.y < yf_limit && vec.y < data->height)
		{
			cubicm_draw(data->f->c_re, data->f->c_im, &vec, data);
			++(vec.y);
		}
		++(vec.x);
	}
}

void		*cubicm_start(void *vdata)
{
	long double img_x;
	long double img_y;
	t_data		*data;

	data = (t_data *)vdata;
	img_x = (data->pos->v2.x - data->pos->v1.x) * data->f->zoom;
	img_y = (data->pos->v2.y - data->pos->v1.y) * data->f->zoom;
	cubicm_compute(img_x, img_y, data);
	pthread_exit(NULL);
	return (NULL);
}
