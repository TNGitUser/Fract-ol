/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:33:57 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 10:15:28 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	main(int ac, char **av)
{	
	t_data	*data;

	if (ac != 2)
		ft_die("usage: ./fractol [julia/mandelbrot] [-t num_of_thread]");
	data = init_main(2, 1);
	mlx_hook(data->mlx_win[0], 2, 0, key_handler, mlx);
	mlx_hook(data->mlx_win[0], 17, 0, win_close, mlx);
	mlx_hook(data->mlx_win[1], 2, 0, key_handler, mlx);
	mlx_hook(data->mlx_win[1], 17, 0, win_close, mlx);
	mlx_loop(data->mlx);
	return (0);
}
