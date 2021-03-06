/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:01:35 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/10 12:30:17 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			key_pressed(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if ((keycode >= 18 && keycode <= 23) || keycode == 26 || keycode == 28)
	{
		if (keycode == 28)
			keycode--;
		frac_manager((keycode < 26 ? keycode % 18 : keycode % 20), data);
	}
	else if (keycode == 67)
		data->f->plocked = !data->f->plocked;
	else if (keycode == 15)
		reset(data);
	if (keycode == 4)
		data->ind = data->ind == 0 ? 1 : 0;
	else if (keycode == 34)
		data->ind = data->ind != 2 ? 2 : 0;
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	show_help(data);
	return (0);
}

int			key_handler(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode >= 83 && keycode <= 86)
		color_manager(keycode % 83, data);
	else if (keycode == 0)
	{
		enable_animation(data, -4, 4);
		return (0);
	}
	else if (keycode == 1)
		data->f->smooth = !data->f->smooth;
	else if (keycode == 24 || keycode == 27)
		keycode == 24 ? iter_update(10, data) : iter_update(-10, data);
	else if (keycode == 69 || keycode == 78)
		zoom_manager(keycode, data);
	else if (keycode >= 123 && keycode <= 126)
		move_update(keycode, data);
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	show_help(data);
	return (0);
}

int			mouse_handler(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 4 || button == 5 || button == 1 || button == 2)
		mzoom_manager(button, x, y, data);
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	show_help(data);
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (!data->f->plocked)
	{
		data->f->c_re = (long double)(x) / data->width;
		data->f->c_im = (long double)(y) / data->height;
		mlx_destroy_image(data->mlx, data->image->ptr);
		data->image->ptr = mlx_new_image(data->mlx, data->width,
				data->height);
		start_dthreads(data);
		show_help(data);
	}
	return (0);
}

int			win_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
