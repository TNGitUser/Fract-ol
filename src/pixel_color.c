/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:07:48 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/27 15:52:46 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	pixel_color(t_data *data, t_vector2 *vec, int color)
{
	int			r;
	int			g;
	int			b;
	int			offset;
	long double img_size;

	if (color == 0)
		return ;
	img_size = data->width * data->height * data->image->bpp / 8;
	if ((vec->x < 0 || vec->y < 0) || vec->y * data->image->line_size + \
			vec->x * data->image->bpp / 8 >= img_size || vec->y >= img_size /\
			data->image->line_size || vec->x >= data->image->line_size /\
			(data->image->bpp / 8))
		return ;
	r = color;
	g = color >> 8;
	b = color >> 16;
	offset = data->image->bpp / 8;
	data->image->img[vec->x * offset + vec->y * data->image->line_size] = r;
	data->image->img[vec->x * offset + 1 + vec->y * data->image->line_size] = g;
	data->image->img[vec->x * offset + 2 + vec->y * data->image->line_size] = b;
}

int		interpolate_color(int color1, int color2, float factor)
{
	int rgb1[3];
	int rgb2[3];
	int gcolor[3];

	rgb1[0] = (color1 >> 16) & 0xFF;
	rgb1[1] = (color1 >> 8) & 0xFF;
	rgb1[2] = (color1) & 0xFF;
	rgb2[0] = (color2 >> 16) & 0xFF;
	rgb2[1] = (color2 >> 8) & 0xFF;
	rgb2[2] = (color2) & 0xFF;
	gcolor[0] = round(rgb1[0] + factor * (rgb2[0] - rgb1[0]));
	gcolor[1] = round(rgb1[1] + factor * (rgb2[1] - rgb1[1]));
	gcolor[2] = round(rgb1[2] + factor * (rgb2[2] - rgb1[2]));
	return (gcolor[0] << 16) | (gcolor[1] << 8) | gcolor[0];
}

int		get_scolor(t_data *data)
{
	if (!data->f->smooth)
	{
		if (data->f->cs == 1)
			return (SINGLECOLOR1);
		else if (data->f->cs == 2)
			return (SINGLECOLOR2);
		else
			return (SINGLECOLOR0);
	}
	else
	{
		if (data->f->cs == 1)
			return (INTER_COLOR1);
		else if (data->f->cs == 2)
			return (INTER_COLOR2);
		else
			return (INTER_COLOR0);
	}
	return (0);
}

int		*color_palette(int c1, int c2, int step)
{
	int		*color_array;
	int		i;
	float	var;

	step = 50;
	var = 1.0 / ((float)step - 1);
	if (!(color_array = malloc(sizeof(int) * step)))
		ft_die("Color array init failed.");
	i = 0;
	while (i < (step))
	{
		color_array[i] = interpolate_color(c1, c2, var * i);
		++i;
	}
	return (color_array);
}

int		normalize_color(int i, t_dvector2 *v, t_data *d)
{
	int			color1;
	int			color2;
	long double nu;
	long double iteration;
	long double log_zn;

	iteration = (long double)i;
	if (i == d->f->iteration)
		return (get_scolor(d));
	if (i < d->f->iteration)
	{
		log_zn = log(v->x * v->x + v->y * v->y) / 2;
		nu = log(log_zn / log(2)) / log(2);
		iteration = iteration + 1 - nu;
	}
	color1 = d->f->palette[((int)floor(iteration)) % 50];
	color2 = d->f->palette[((int)(floor(iteration) + 1)) % 50];
	return (interpolate_color(color1, color2, iteration -
				floor(iteration)));
}
