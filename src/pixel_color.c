/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:07:48 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 16:25:45 by lucmarti         ###   ########.fr       */
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
