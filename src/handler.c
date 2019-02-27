/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:01:35 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/27 15:39:39 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			key_pressed(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode >= 18 && keycode <= 21)
		frac_manager(keycode % 18, data);
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	return (0);
}

int			key_handler(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode >= 83 && keycode <= 85)
		color_manager(keycode % 83, data);
	else if (keycode == 0)
	{
		data->f->plocked = 1;
		enable_animation(data, -4,  4);
		return (0);
	}
	else if (keycode == 1)
		data->f->smooth = !data->f->smooth;
	else if (keycode == 24 || keycode == 27)
		keycode == 24 ? iter_update(10, data) : iter_update(-10, data);
	else if (keycode == 69 || keycode == 78)
		data->f->zoom *= (keycode == 69 ? 2 : 0.5);
	else if (keycode == 67)
		data->f->plocked = !data->f->plocked;
	else if (keycode >= 123 && keycode <= 126)
		move_update(keycode, data);
	else if (keycode == 15)
		reset(data);
	mlx_destroy_image(data->mlx, data->image->ptr);
	data->image->ptr = mlx_new_image(data->mlx, data->width, data->height);
	start_dthreads(data);
	return (0);
}

int			mouse_handler(int button, int x, int y, void *param)
{
	double	xr;
	double	xi;
	t_data *data;

	data = (t_data *)param;
	if (button == 4 || button == 5 || button == 1 || button == 2)
	{
		//printf("Current v1 : (%Lf,%Lf)\n", data->pos->v1.x, data->pos->v1.y);
		//printf("Mouse : (%i,%i)\n", x, y);
		xi = ((float)y / data->width) * ft_abs(data->pos->v1.y) + data->pos->v1.y;
		xr = ((float)x / data->width) * ft_abs(data->pos->v1.x) + data->pos->v1.x;
		//printf("New v1 : (%f,%f)\n", xi, xr);
		/*data->pos->v1.x = xr;
		  data->pos->v1.y = xi;
		  printf("New v1 : (%f,%f)\n", xr, xi);
		  if (button == 5 || button == 1)
		  data->f->zoom *= 2;
		  if (button == 4 || button == 2)
		  data->f->zoom *= 0.5;*/
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
		printf("real part : %f\n", data->f->c_re);
		printf("imag part : %f\n", data->f->c_im);
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
