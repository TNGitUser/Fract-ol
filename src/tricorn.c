/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:42:35 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/09 13:49:13 by lucmarti         ###   ########.fr       */
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

static void	tri_draw(long double x, long double y, t_vector2 *v, t_data *data)
{
	long double	zr;
	long double zi;
	long double tmp;
	int			i;
	t_dvector2	vz;

	x = v->x / data->f->zoom + data->pos->v1.x;
	y = v->y / data->f->zoom + data->pos->v1.y;
	zr = x;
	zi = y;
	i = 0;
	while (i < data->f->iteration && zr * zr + zi * zi < 4)
	{
		tmp = zr * zr - zi * zi;
		zi = -2 * zr * zi + y;
		zr = tmp + x;
		++i;
	}
	vz.x = zr;
	vz.y = zi;
	color(i, data, v, normalize_color(i, &vz, data));
}

static void	tri_compute(long double xf_limit, long double yf_limit,
		t_data *data)
{
	t_vector2	vec;
	int			offset;
	int			start;

	offset = data->width / data->threads->nth;
	start = offset * get_thread(data, pthread_self());
	vec.x = start - 1;
	while (vec.x < xf_limit && vec.x < data->width && vec.x < start + offset)
	{
		vec.y = 0;
		while (vec.y < yf_limit && vec.y < data->height)
		{
			tri_draw(data->f->c_re, data->f->c_im, &vec, data);
			++(vec.y);
		}
		++(vec.x);
	}
}

void		*tri_start(void *vdata)
{
	long double img_x;
	long double img_y;
	t_data		*data;

	data = (t_data *)vdata;
	img_x = (data->pos->v2.x - data->pos->v1.x) * data->f->zoom;
	img_y = (data->pos->v2.y - data->pos->v1.y) * data->f->zoom;
	tri_compute(img_x, img_y, data);
	pthread_exit(NULL);
	return (NULL);
}
