/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:33:57 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/09 13:42:26 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		init_draw(t_data *data)
{
	t_image	*img;

	img = data->image;
	if (!(img->ptr = mlx_new_image(data->mlx, data->width,
					data->height)))
		ft_die("Image ptr init failed.");
	if (!(img->img = mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line_size)\
					, &(img->endian))))
		ft_die("Image retrieving failed.");
	start_dthreads(data);
	show_help(data);
	mlx_key_hook(data->mlx_win, key_pressed, data);
	mlx_hook(data->mlx_win, 2, 0, key_handler, data);
	mlx_hook(data->mlx_win, 4, 0, mouse_handler, data);
	mlx_hook(data->mlx_win, 6, 0, mouse_move, data);
	mlx_hook(data->mlx_win, 17, 0, win_close, data);
	mlx_loop(data->mlx);
}

static int	check_type(char *str)
{
	if (ft_strcmp("julia", str) == 0)
		return (0);
	else if (ft_strcmp("mandelbrot", str) == 0)
		return (1);
	else if (ft_strcmp("tricorn", str) == 0)
		return (2);
	else if (ft_strcmp("burningship", str) == 0)
		return (3);
	else if (ft_strcmp("cubem", str) == 0)
		return (4);
	else if (ft_strcmp("perpendicularbs", str) == 0)
		return (5);
	else if (ft_strcmp("quadicm", str) == 0)
		return (6);
	else if (ft_strcmp("arrow", str) == 0)
		return (7);
	return (-1);
}

int			main(int ac, char **av)
{
	int		type;
	t_data	*data;

	type = 0;
	data = NULL;
	(void)av;
	if (ac != 2)
		ft_die("usage: ./fractol [julia | mandelbrot | tricorn | burningship"
				" | perpendicularbs | cubem | quadicm | arrow]");
	if ((type = check_type(av[1])) == -1)
		ft_die("usage: ./fractol [julia | mandelbrot | tricorn | burningship"
				" | perpendicularbs | cubem | quadicm | arrow]");
	data = init_main(THREADS_NUM, type);
	return (0);
}
