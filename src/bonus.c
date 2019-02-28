/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:49:45 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/28 12:31:02 by lucmarti         ###   ########.fr       */
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
	t_dvector2	scenter;

	scenter = get_center(data, keycode == 69 ? 1 : -1);
	printf("Before zoom : (%Lf,%Lf)\n", data->pos->v1.x, data->pos->v1.y);
	printf("Before zoom : Screen center : (%Lf,%Lf)\n", scenter.x, scenter.y);
	if (data->z + (keycode == 69 ? 1 : -1) > -1)
	{
		z = keycode == 69 ? 2 : 0.5;
		data->f->zoom *= z;
		data->z += (keycode == 69 ? 1 : -1);
		if (z < 1)
		{
			data->pos->v1.x -= data->f->move.x;
			data->pos->v1.y -= data->f->move.y;
		}
		else
		{
			data->pos->v1.x = data->pos->origin.x / ft_power(2, data->z) + data->f->move.x;
			data->pos->v1.y = data->pos->origin.y / ft_power(2, data->z) + data->f->move.y;
		}
	}
	printf("Screen center : (%Lf,%Lf)\n", scenter.x, scenter.y);
	printf("True pos : (%Lf,%Lf)\n", data->pos->v1.x, data->pos->v1.y);
}

t_dvector2	get_center(t_data *data, int z)
{
	t_dvector2 scenter;

	if (z == -1)
	{
		scenter.x = ((long double)300 / (long double)data->width) / (data->pos->origin.x * data->z);
		scenter.y = ((long double)300 / (long double)data->height) / (data->pos->origin.y * data->z);
	}
	else
	{
		scenter.x = ((long double)300 / (long double)data->width) * (data->pos->origin.x / (data->z + 1));
		scenter.y = ((long double)300 / (long double)data->height) * (data->pos->origin.y / (data->z + 1));
	}
	printf("Screen center : (%Lf,%Lf)\n", scenter.x, scenter.y);
	printf("test : (%Lf,%Lf)\n", data->pos->v2.x/2 + data->pos->v1.x,\
			data->pos->v2.y/2 + data->pos->v1.y);
	return (scenter);
}
