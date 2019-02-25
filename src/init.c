/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:34:00 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 10:07:54 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static t_thr	*init_threads(int thread_number)
{
	t_thr	*threads;

	if (!(threads = malloc(sizeof(t_thr))))
		ft_die("Threads init failed.");
	threads->nth = thread_number;
	if (!(threads->workers = malloc(sizeof(pthread_t) * thread_number)))
		ft_die("Workers init failed.");
	return (t_thr);
}

t_data			*init_main(int display_number, int thread_number)
{
	t_data *data;

	data = NULL;
	if (!(data = malloc(sizeof(t_data))))
		ft_die("Init failed.");
	if (!(data->mlx = mlx_init(void)))
		ft_die("mlx init failed.");
	if (!(data->mlx_win[0] = mlx_new_window(data->mlx, 1000, 1000, "0")) || !(data->mlx_win[1] = mlx_new_window(data->mlx, 1000,1000 "1")))
		ft_die("mlx init failed.");
	data->width = 1000;
	data->height = 1000;
	data->threads = init_threads(thread_number);
	return (data);
}
