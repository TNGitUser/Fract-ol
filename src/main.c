/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:33:57 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 10:41:01 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	(void)av;
	if (ac != 2)
		ft_die("usage: ./fractol [julia/mandelbrot] [-t num_of_thread]");
	if (ft_strcmp("julia", av[1]) == 0)
	{
		data = init_main(1, 0);
		ft_putendl("Julia selected");
	}
	else if (ft_strcmp("mandelbrot", av[1]) == 0)
	{
		data = init_main(1, 1);
		ft_putendl("Mandelbrot selected");
	}
	else
		ft_die("usage: ./fractol [julia/mandelbrot] [-t num_of_thread]");
	mlx_hook(data->mlx_win, 2, 0, key_handler, data);
	mlx_hook(data->mlx_win, 17, 0, win_close, data);
	mlx_loop(data->mlx);
	return (0);
}
