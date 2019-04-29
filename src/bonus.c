/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:49:45 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/10 11:16:10 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			enable_animation(t_data *data, float start, float end)
{
	float os;

	data->f->plocked = 1;
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

void		zoom_manager(int keycode, t_data *data)
{
	double z;

	if (data->z + (keycode == 69 ? 1 : -1) > -1)
	{
		z = keycode == 69 ? 1.2 : 1. / 1.2;
		data->pos->v1.x = (300 / data->f->zoom + data->pos->v1.x) - (300 /\
				(data->f->zoom * z));
		data->pos->v1.y = (300 / data->f->zoom + data->pos->v1.y) - (300 /\
				(data->f->zoom * z));
		data->f->zoom *= z;
		data->z += (keycode == 69 ? 1 : -1);
	}
}

void		mzoom_manager(int button, int x, int y, t_data *data)
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

static void	show_indicator(t_data *data)
{
	char *msg;

	if (data->ind != 2)
		return ;
	msg = ft_itoa(data->threads->nth);
	mlx_string_put(data->mlx, data->mlx_win,
			10, 520, 0xFFFFFF, "Threads   : ");
	mlx_string_put(data->mlx, data->mlx_win,
			130, 520, 0xFFFFFF, msg);
	ft_memdel((void **)&msg);
	msg = ft_itoa(data->z);
	mlx_string_put(data->mlx, data->mlx_win,
			10, 540, 0xFFFFFF, "Zoom      : ");
	mlx_string_put(data->mlx, data->mlx_win,
			130, 540, 0xFFFFFF, msg);
	ft_memdel((void **)&msg);
	msg = ft_itoa(data->f->iteration);
	mlx_string_put(data->mlx, data->mlx_win,
			10, 560, 0xFFFFFF, "Iteration : ");
	mlx_string_put(data->mlx, data->mlx_win,
			130, 560, 0xFFFFFF, msg);
	ft_memdel((void **)&msg);
}

void		show_help(t_data *data)
{
	if (data->ind == 1)
	{
		mlx_string_put(data->mlx, data->mlx_win,
				10, 10, 0xFFFFFF, "Zoom             : '+' and '-'");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 30, 0xFFFFFF, "Iteration        : '_' and '='");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 50, 0xFFFFFF, "Julia animation  : 'a'");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 70, 0xFFFFFF, "Colors           : '[(Numpad)1|2|3|4]'");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 90, 0xFFFFFF, "Move             : arrow keys");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 110, 0xFFFFFF, "Reset            : 'r'");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 130, 0xFFFFFF, "Help             : 'h'");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 150, 0xFFFFFF, "Smooth           : 's'");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 170, 0xFFFFFF, "Indicators       : 'i'");
		mlx_string_put(data->mlx, data->mlx_win,
				10, 190, 0xFFFFFF, "Quit             : 'Esc'");
	}
	show_indicator(data);
}
