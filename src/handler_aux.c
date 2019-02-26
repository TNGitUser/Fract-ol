/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:49:33 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/26 16:26:46 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	iter_update(int mod, t_data *data)
{
	printf("%d\n", data->f->iteration);
	if (data->f->iteration + (mod * 2) <= 1.)
		data->f->iteration = 10;
	else
		data->f->iteration += mod;
	data->f->iteration = data->f->iteration <= 0 ? 1 : data->f->iteration;
	ft_memdel((void **)&(data->f->palette));
	data->f->palette = color_palette(0, 0x0a2440, data->f->iteration);
}

void	move_update(int keycode, t_data *data)
{
	if (keycode == 123 || keycode == 124)
		data->pos->v1.x = keycode == 123 ? data->pos->v1.x + \
						(0.1 / (data->f->zoom / 1000)) : \
						data->pos->v1.x - (0.1 / (data->f->zoom / 1000));
	else if (keycode == 125 || keycode == 126)
		data->pos->v1.y = keycode == 126 ? data->pos->v1.y + \
						(0.1 / (data->f->zoom / 1000)) : \
						data->pos->v1.y - (0.1 / (data->f->zoom / 1000));
}

void	reset(t_data *data)
{
	data->f->zoom = 100;
	data->f->iteration = 50;
	data->pos->v1.x = -2.92;
	data->pos->v1.y = -2.92;
}

void	mouse_zoom(int keycode, int x, int y, t_data *data)
{
	(void)keycode;
	(void)x;
	(void)y;
	(void)data;
}

void	frac_manager(int type, t_data *data)
{
	if (type != data->f->type)
		data->f->type = type;
}
