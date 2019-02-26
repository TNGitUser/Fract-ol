/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:07:48 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/26 12:14:51 by lucmarti         ###   ########.fr       */
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

int		lerp(long double v0, long double v1, long double t)
{
	return (1 - t) * v0 + t * v1;
}

int		normalize_color(int i, int max_i, long double x, long double y)
{
	int			color1;
	int			color2;
	long double nu;
	long double iteration;
	long double log_zn;

	iteration = (long double)i;
	if (i < max_i)
	{
		log_zn = log(x * x + y * y) / 2;
		nu = log(log_zn / log(2)) / log(2);
		iteration = iteration + 1 - nu;
	}
	color1 = 0x0a2440 * (int)floor(iteration);
	color2 = 0x0a2440 * (int)(floor(iteration) + 1);
	return (lerp(color1, color2, iteration - (long long)iteration));
}
