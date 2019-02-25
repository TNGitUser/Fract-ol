/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:27:30 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 16:00:25 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	start_dthreads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->threads->nth)
	{
		if (pthread_create(&(data->threads->workers[i]), NULL,
				data->draw[data->f->type], data))
			ft_die("Thread could not be created.");
		++i;
	}
	i = 0;
	while (i < data->threads->nth)
	{
		if (pthread_join(data->threads->workers[i], NULL))
			ft_die("Thread could not join main thread.");
		++i;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image->ptr, 0, 0);
}

int		get_thread(t_data *data, pthread_t thr)
{
	int i;

	i = 0;
	while (i < data->threads->nth &&
			!pthread_equal(thr, data->threads->workers[i]))
		++i;
	return (i);
}
