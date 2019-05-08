/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reelbour <reelbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:53:24 by reelbour          #+#    #+#             */
/*   Updated: 2019/05/08 16:24:51 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx/mlx.h"
# include "../lib/gnl/get_next_line.h"
# include <math.h>
# define W 2600
# define H 1800
# define V 5
# include <stdio.h>

typedef struct	s_m
{
	int		nb_l;
	int		nb_w;
	int		i;
	int		j;
	int		**coord;
}				t_m;

typedef struct	s_ml
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ml;

typedef struct	s_v
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		dx;
	int		dy;
	int		e;
	int		e2;
	int		ix;
	int		iy;
}				t_v;

/*
** ==================== FUNCTIONS IN INIT_MAP.C ==================== **
*/

void			init_m(t_m *m);
void			read_m(int fd, t_m *m);
int				count_words(char *str);
void			stock_int_tab(char *str, t_m *m);

/*
** ==================== FUNCTIONS IN VALIDATION.C ==================== **
*/

void			ft_error(int n);
void			render_m(t_m *m);
#endif
