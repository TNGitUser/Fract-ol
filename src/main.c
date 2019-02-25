/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:33:57 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 14:49:23 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	init_draw(t_data *data)
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
	mlx_hook(data->mlx_win, 2, 0, key_handler, data);
	mlx_hook(data->mlx_win, 6, 0, mouse_handler, data);
	mlx_loop(data->mlx);
}

int		main(int ac, char **av)
{
	int		type;
	t_data	*data;

	type = 0;
	data = NULL;
	(void)av;
	if (ac != 2)
		ft_die("usage: ./fractol [julia/mandelbrot] [-t num_of_thread]");
	if (ft_strcmp("julia", av[1]) == 0)
	{
		type = 0;
		ft_putendl("Julia selected");
	}
	else if (ft_strcmp("mandelbrot", av[1]) == 0)
	{
		type = 1;
		ft_putendl("Mandelbrot selected");
	}
	else
		ft_die("usage: ./fractol [julia/mandelbrot] [-t num_of_thread]");
	data = init_main(1, type);
	return (0);
}
