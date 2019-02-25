/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:33:55 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/25 10:17:17 by lucmarti         ###   ########.fr       */
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
}				t_frac;

typedef	struct	s_thr
{
	int			nth;
	pthread_t	**workers;
}				t_thr

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_img;
	void		*(mlx_win[2]);
	t_thr		*threads;
	int			width;
	int			height;
}				t_data;

/*
**		main.c
*/

/*
**		init.c
*/
t_data			*init_main(int display_number, int thread_number);

/*
**		handle.c
*/
int				key_handler(void *param);
int				win_close(void *param);

/*
**		err.c
*/
void			ft_die(char *msg);

#endif
