/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:01:35 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/26 12:14:15 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			key_handler(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 1)
		data->f->smooth = !data->f->smooth;
	if (keycode == 24 || keycode == 27)
		data->f->iteration += (keycode == 24 ? 100 : -100);
	if (keycode == 69 || keycode == 78)
		data->f->zoom *= (keycode == 69 ? 2 : 0.5);
	if (keycode == 67)
		data->f->plocked = !data->f->plocked;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move_update(keycode, data);
	if (keycode == 15)
		reset(data);
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	return (0);
}

int			mouse_handler(int button, int x, int y, void *param)
{
	t_data *data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	printf("button : %i\n", button);
	if (button == 4 || button == 5 || button == 1 || button == 2)
	{
		printf("Current v1 : (%f,%f)\n", data->pos->v1.x, data->pos->v1.y);
		printf("Mouse : (%i,%i)\n", x, y);
		data->pos->v1.x = ((float)x / (data->width / 2)) - 1 *\
						data->f->zoom / 100;
		data->pos->v1.y = ((float)y / (data->height / 2)) - 1 *\
						data->f->zoom / 100;
		printf("New v1 : (%f,%f)\n", data->pos->v1.x, data->pos->v1.y);
		if (button == 5 || button == 1)
			data->f->zoom *= 1.2;
		if (button == 4 || button == 2)
			data->f->zoom *= 0.9;
	}
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	return (0);
}

int			mouse_move(int x, int y, void *param)
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
