/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reelbour <reelbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:53:24 by reelbour          #+#    #+#             */
/*   Updated: 2019/05/13 12:06:57 by ahammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx/mlx.h"
# include "../lib/gnl/get_next_line.h"
# include <math.h>
# define W 1500
# define H 1200
# define V 20
# include <stdio.h>

typedef struct	s_m
{
	int		nb_l;
	int		nb_w;
	int		x;
	int		y;
	int		**coord;
}				t_m;

typedef struct	s_ml
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ml;

typedef struct	s_u
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		dx;
	int		dy;
	int		e;
}				t_v;

/*
** ==================== FUNCTIONS IN INIT_MAP.C ==================== **
*/

void			init_m(t_m *m);
void			read_m(int fd, t_m *m);
int				count_words(char *str);
void			stock_int_tab(char *str, t_m *m);
void 			ft_secure_malloc(t_m *m, char **nb, char **split);

/*
** ==================== FUNCTIONS IN VALIDATION.C ==================== **
*/

void			ft_error(int n);
void			render_m(t_m *m);
void			draw_line(t_v *v, t_ml *ml);
void 			draw_map(t_m *m, t_v *v, t_ml *ml);
void			testcases(t_v *v, t_ml *ml);
#endif
