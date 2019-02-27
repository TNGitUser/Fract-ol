/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:49:45 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/27 15:38:50 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <time.h>
int		enable_animation(t_data *data, float start, float end)
{
	float os;

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
