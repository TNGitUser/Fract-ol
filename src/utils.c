/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:52:21 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 15:17:02 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	init_image(t_data *data)
{
	t_image	*image;

	if (!(image = malloc(sizeof(t_image))))
		ft_die("Image init failed.");
	image->ptr = NULL;
	image->img = NULL;
	image->bpp = 0;
	image->line_size = 0;
	image->endian = 0;
	data->image = image;
	init_draw(data);
}

void	init_pos(t_data *data)
{
	t_pos	*pos;

	if (!(pos = malloc(sizeof(t_pos))))
		ft_die("Pos init failed.");
	pos->v1.x = -2.99;
	pos->v1.y = -2.99;
	pos->v2.x = 5;
	pos->v2.y = 5;
	pos->vmouse.x = 0;
	pos->vmouse.y = 0;
	pos->h = 0;
	data->pos = pos;
	init_image(data);
}

void	init_threads(t_data *data, int thread_number)
{
	t_thr	*threads;

	if (!(threads = malloc(sizeof(t_thr))))
		ft_die("Threads init failed.");
	threads->nth = thread_number;
	if (!(threads->workers = malloc(sizeof(pthread_t) * thread_number)))
		ft_die("Workers init failed.");
	data->threads = threads;
	init_farray(data);
	init_pos(data);
}

void	init_farray(t_data *data)
{
	data->draw[0] = &julia_start;
	data->draw[1] = &julia_start;
}
