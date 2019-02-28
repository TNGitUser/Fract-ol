/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:49:45 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/28 13:07:51 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int		enable_animation(t_data *data, float start, float end)
{
	float os;

	os = start;
	if (data->f->type == 0 && data->ea == 0)
	{
		data->ea = 1;
		while (start <= end)
		{
			start += 0.01;
			data->f->c_re = start;
			start_dthreads(data);
			mlx_do_sync(data->mlx);
		}
		while (start >= os)
		{
			start -= 0.01;
			data->f->c_re = start;
			start_dthreads(data);
			mlx_do_sync(data->mlx);
		}
	}
	return (0);
}

void	zoom_manager(int keycode, t_data *data)
{
	double z;

	if (data->z + (keycode == 69 ? 1 : -1) > -1)
	{
		z = keycode == 69 ? 1.2 : 1./1.2;
		data->pos->v1.x = (300 / data->f->zoom + data->pos->v1.x) - (300 /\
				(data->f->zoom * z));
		data->pos->v1.y = (300 / data->f->zoom + data->pos->v1.y) - (300 /\
				(data->f->zoom * z));
		data->f->zoom *= z;
		data->z += (keycode == 69 ? 1 : -1);
	}
}

void	mzoom_manager(int button, int x, int y, t_data *data)
{
	double z;

	if (button == 5 || button == 1)
		z = 1.2;
	else
		z = 1 / 1.2;
	if (data->z + (z > 1 ? 1 : -1) > -1)
	{
		data->pos->v1.x = (x / data->f->zoom + data->pos->v1.x) - (x /\
				(data->f->zoom * z));
		data->pos->v1.y = (y / data->f->zoom + data->pos->v1.y) - (y /\
				(data->f->zoom * z));
		data->f->zoom *= z;
		data->z += (z > 1 ? 1 : -1);
	}
}
