/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:01:35 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 15:53:16 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"


int			key_handler(int keycode, void *param)
{
	t_data *data;

	printf("keycode : %i\n", keycode);
	data = (t_data *)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69 || keycode == 78)
		data->f->zoom += (keycode == 69 ? 10 : -10);
	if (keycode == 67)
		data->f->plocked = data->f->plocked ? 0 : 1;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move_update(keycode, data);
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	return (0);
}

int			mouse_handler(int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (!data->f->plocked)
	{
		data->f->c_re = -0.7 + (((float)x / 2 * (float)y / 2) / 100000);
		data->f->c_im = 0.27015 + (((float)x / 2 * (float)y / 2) / 100000);
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
