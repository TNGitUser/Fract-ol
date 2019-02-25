/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:33:55 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 15:52:45 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <pthread.h>

#include <stdio.h>

typedef	struct	s_frac
{
	int			type;
	int			plocked;
	int			iteration;
	double		zoom;
	t_vector2	move;
	double		c_re;
	double		c_im;
}				t_frac;

typedef	struct	s_thr
{
	int			nth;
	pthread_t	*workers;
}				t_thr;

typedef struct	s_image
{
	void		*ptr;
	char		*img;
	int			bpp;
	int			line_size;
	int			endian;
}				t_image;

typedef	struct	s_pos
{
	t_dvector2	v1;
	t_dvector2	v2;
	int			h;
	t_dvector2	vmouse;
}				t_pos;

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*(*draw[2]) (void *);
	int			width;
	int			height;
	t_pos		*pos;
	t_image		*image;
	t_thr		*threads;
	t_frac		*f;
}				t_data;

/*
**		main.c
*/
void			init_draw(t_data *data);

/*
**		julia.c
*/
void			*julia_start(void *vdata);

/*
**		init.c
*/
t_data			*init_main(int thread_number, int type);

/*
**		handler.c
*/
int				key_handler(int keycode, void *param);
int				mouse_handler(int x, int y, void *param);
int				win_close(void *param);

/*
**		handler_aux.c
*/
void			move_update(int keycode, t_data *data);

/*
**		utils.c
*/
void			init_image(t_data *data);
void			init_pos(t_data *data);
void			init_threads(t_data *data, int thread_number);
void			init_farray(t_data *data);

/*
**		threads.c
*/
void			start_dthreads(t_data *data);
int				get_thread(t_data *data, pthread_t thr);

/*
**		pixel_color.c
*/
void			pixel_color(t_data *data, t_vector2 *vec, int color);

/*
**		err.c
*/
void			ft_die(char *msg);

#endif
