/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:01:35 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 10:11:19 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int			key_handler(int keycode, void *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
}

int			win_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
