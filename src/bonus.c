/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:49:45 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/27 17:05:57 by lucmarti         ###   ########.fr       */
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

	if (data->z + (keycode == 69 ? 1 : - 1) > -1)
	{
		z = keycode == 69 ? 2 : 0.5;
		data->f->zoom *= z;
		data->z += (keycode == 69 ? 1 : -1);
		if (z < 0)
		{
			data->pos->v1.x = data->pos->origin.x * (0.5 * (data->z));
			data->pos->v1.y = data->pos->origin.y * (0.5 * (data->z));
		}
		else
		{
			data->pos->v1.x = data->pos->origin.x / (ft_power(2, data->z));
			data->pos->v1.y = data->pos->origin.y / (ft_power(2 ,data->z));
		}
	}
	printf("Current v1 : (%Lf,%Lf)\n", data->pos->v1.x, data->pos->v1.y);
}
