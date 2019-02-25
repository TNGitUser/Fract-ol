/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:33:55 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 11:01:32 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H_
# define CORE_H_

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <pthread.h>

typedef	struct	s_frac
{
	t_vector2	area[2];
	double		zoom;
	t_vector2	move;
	double		cRe;
	double		cIm;
}				t_frac;

typedef	struct	s_thr
{
	int			nth;
	pthread_t	**workers;
}				t_thr;

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_img;
	void		*mlx_win;
	t_thr		*threads;
	int			width;
	int			height;
	t_frac		*f;
}				t_data;

/*
**		main.c
*/

/*
**		julia.c
*/
void			*julia_start(void *vdata);

/*
**		init.c
*/
t_data			*init_main(int thread_number, int type);

/*
**		handle.c
*/
int				key_handler(int keycode, void *param);
int				win_close(void *param);

/*
**		err.c
*/
void			ft_die(char *msg);

#endif
