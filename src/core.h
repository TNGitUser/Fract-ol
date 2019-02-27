/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:33:55 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/27 11:33:19 by lucmarti         ###   ########.fr       */
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

# include <stdio.h>

typedef	struct	s_frac
{
	int			type;
	int			plocked;
	int			smooth;
	int			iteration;
	long double	zoom;
	t_vector2	move;
	double		c_re;
	double		c_im;
	int			*palette;
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
	t_dvector2	vmouse;
}				t_pos;

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*(*draw[4]) (void *);
	t_frac		*(*init[4]) (void);
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
**		julia.c | mandelbrot.c
*/
void			*julia_start(void *vdata);
void			*man_start(void *vdata);
void			*tri_start(void *vdata);
void			*burn_start(void *vdata);

/*
**		init.c
*/
t_frac			*init_julia(void);
t_frac			*init_mandelbrot(void);
t_frac			*init_tri(void);
t_frac			*init_burn(void);
t_data			*init_main(int thread_number, int type);

/*
**		handler.c
*/
int				key_pressed(int keycode, void *param);
int				key_handler(int keycode, void *param);
int				mouse_handler(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
int				win_close(void *param);

/*
**		handler_aux.c
*/
void			iter_update(int mod, t_data *data);
void			move_update(int keycode, t_data *data);
void			mouse_zoom(int keycode, int x, int y, t_data *data);
void			reset(t_data *data);
void			frac_manager(int type, t_data *data);

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
int				*color_palette(int c1, int c2, int step);
int				normalize_color(int i, t_dvector2 *v, t_data *d);

/*
**		err.c
*/
void			ft_die(char *msg);

#endif
