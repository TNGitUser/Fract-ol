/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:01:35 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 14:49:19 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <stdio.h>
int			key_handler(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	return (0);
}

int			mouse_handler(int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (x > 0 && x < data->width)
		if (y > 0 && y < data->height)
		{
			data->f->c_re = 0.285 + (((float)x / 2 * (float)y / 2) / 1000);
			data->f->c_im = 0.285 + (((float)x / 2 * (float)-y / 2) / 1000);
			mlx_destroy_image(data->mlx, data->image->ptr);
			data->image->ptr = mlx_new_image(data->mlx, data->width,
					data->height);
			start_dthreads(data);
		}
	return (0);
}

int			win_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
